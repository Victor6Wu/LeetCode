#pragma once
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
//return the area of the largest rectangle in the histogram.
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: 暴力解法，两层循环，算出所有矩形面积，比较大小
	int largestRectangleArea1(vector<int>& heights) {
		int n = heights.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int h = heights[i];
			for (int j = i; j < n; ++j) {
				h = min(h, heights[j]);
				int Area = (j - i + 1) * h;
				ans = max(ans, Area);
			}
		}
		return ans;
	}

	//solution 2: 单调栈法，类似于No_42
	int largestRectangleArea2(vector<int>& heights) {
		heights.push_back(0);							//数组末尾增添哨兵节点作为右边界
		int n = heights.size();
		int current = 0, area = 0;
		stack<int> st;
		while (current < n) {
			while (!st.empty() && heights[current] < heights[st.top()]) {				//必须要有判断非空的条件，因为要与栈顶比较大小
				int top = st.top();														//栈顶用于得到矩形的高
				st.pop();																//去除栈顶以产生新的栈顶，用于获取左边界

				if (!st.empty() && (heights[top] == heights[st.top()])) {				//在栈非空的情况下，与当前栈顶等高，则跳过当前栈顶
					continue;
				}
				if (!st.empty()) {														//新栈顶非空的时候可以作为左边界
					int temp = (current - st.top() - 1) * heights[top];
					area = max(area, temp);
				}	
				else {																	//当没有新栈顶时，数组最前面的-1位置为左边界，认为高度为0
					int temp = current  * heights[top];
					area = max(area, temp);
				}

			}
			st.push(current++);
		}
		return	area;
	 }

	//solution 2+: 2的优化，可以再在数组前面增添一个哨兵0，这样可以省去一次栈的空判断，代码更整齐
	//solution 3：构建两个数组用于存放每个高度的左右边界，最后用一个循环统一计算，类似于No_42动态规划的方法，不是当场计算，而是最后计算
	int largestRectangleArea3(vector<int>& heights) {
		int n = heights.size();
		vector<int> left(n), right(n, n);				//左边界都初始化为0，右边界都初始化为数组的长度

		stack<int> mono_stack;
		for (int i = 0; i < n; ++i) {
			while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
				right[mono_stack.top()] = i;
				mono_stack.pop();
			}
			left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
			mono_stack.push(i);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};
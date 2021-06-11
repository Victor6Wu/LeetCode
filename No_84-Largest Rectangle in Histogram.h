#pragma once
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
//return the area of the largest rectangle in the histogram.
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: �����ⷨ������ѭ����������о���������Ƚϴ�С
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

	//solution 2: ����ջ����������No_42
	int largestRectangleArea2(vector<int>& heights) {
		heights.push_back(0);							//����ĩβ�����ڱ��ڵ���Ϊ�ұ߽�
		int n = heights.size();
		int current = 0, area = 0;
		stack<int> st;
		while (current < n) {
			while (!st.empty() && heights[current] < heights[st.top()]) {				//����Ҫ���жϷǿյ���������ΪҪ��ջ���Ƚϴ�С
				int top = st.top();														//ջ�����ڵõ����εĸ�
				st.pop();																//ȥ��ջ���Բ����µ�ջ�������ڻ�ȡ��߽�

				if (!st.empty() && (heights[top] == heights[st.top()])) {				//��ջ�ǿյ�����£��뵱ǰջ���ȸߣ���������ǰջ��
					continue;
				}
				if (!st.empty()) {														//��ջ���ǿյ�ʱ�������Ϊ��߽�
					int temp = (current - st.top() - 1) * heights[top];
					area = max(area, temp);
				}	
				else {																	//��û����ջ��ʱ��������ǰ���-1λ��Ϊ��߽磬��Ϊ�߶�Ϊ0
					int temp = current  * heights[top];
					area = max(area, temp);
				}

			}
			st.push(current++);
		}
		return	area;
	 }

	//solution 2+: 2���Ż���������������ǰ������һ���ڱ�0����������ʡȥһ��ջ�Ŀ��жϣ����������
	//solution 3�����������������ڴ��ÿ���߶ȵ����ұ߽磬�����һ��ѭ��ͳһ���㣬������No_42��̬�滮�ķ��������ǵ������㣬����������
	int largestRectangleArea3(vector<int>& heights) {
		int n = heights.size();
		vector<int> left(n), right(n, n);				//��߽綼��ʼ��Ϊ0���ұ߽綼��ʼ��Ϊ����ĳ���

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
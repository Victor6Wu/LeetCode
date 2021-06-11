#pragma once
//Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it can trap after raining.
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	//solution 1: 暴力解法，每个位置的盛水量由左右两侧最大值中较小的那个决定 
	int trap1(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int leftMax = 0, rightMax = 0;
			//此处循环时，以i为中心向两边找最大值，起点必须包括i，
			//否则会出现(min(leftMax, rightMax) - height[i])为负数的情况
			for (int j = i; 0 <= j; --j) {
				leftMax = max(leftMax, height[j]);
			}
			for (int j = i; j < n; ++j) {
				rightMax = max(rightMax, height[j]);
			}
			ans = ans + (min(leftMax, rightMax) - height[i]);
		}
		return ans;
	}

	//solution 2：动态规划法，依据solution 1 的思路，提前将每个位置的左、右最大值计算出来，存入数组，最后直接计算求和
	int trap2(vector<int>& height) {
		int n = height.size();
		if (n < 3) return 0;
		int ans = 0;
		vector<int> leftMax(n), rightMax(n);
		//构建左边最大值数组
		leftMax[0] = height[0];
		for (int i = 1; i < n; ++i) {
			leftMax[i] = max(leftMax[i - 1], height[i]);
		}
		//构建右边最大值数组
		rightMax[n-1] = height[n-1];
		for (int i = n-2; 0 <= i; --i) {
			rightMax[i] = max(rightMax[i + 1], height[i]);
		}
		//计算盛水量
		for (int i = 0; i < n; ++i) {
			ans = ans + (min(leftMax[i], rightMax[i]) - height[i]);
		}
		return ans;
	}

	//solution 3: 栈法，递减栈
	int trap3(vector<int>& height) {
		int n = height.size();
		int ans = 0, current = 0;
		stack<int> st;
		while (current < n) {
			while (!st.empty() && height[current] > height[st.top()]) {
				//作为凹坑的底
				int top = st.top();			
				st.pop();
				//必须检查栈是否为空，接下来的栈顶用作凹坑的左边界
				if (st.empty())
					break;
				int distance = current - st.top() - 1;
				int bounded_height = min(height[current], height[st.top()]) - height[top];
				ans = ans + bounded_height * distance;
			}
			st.push(current++);
		}
		return ans;
	}

	//solution 4: 双指针法，固定较高的指针，移动矮指针并就算每处盛水量，当高于之前固定的指针时，再交换移动
	int trap4(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0;
		//初始化左右最大值
		int leftMax = 0, rightMax = 0;
		while (left < right) {
			if (height[left] < height[right]) {
				height[left] >= leftMax ? (leftMax = height[left]) : ans += (leftMax - height[left]);
				++left;
			}
			else {
				height[right] >= rightMax ? (rightMax = height[right]) : ans += (rightMax - height[right]);
				--right;
			}
		}
		return ans;
	}
};
#pragma once
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: 暴力解法，先构建一个简单的成员函数，用于计算两个垂线间的面积,时间复杂度O(n^2)，效果太差
	int computeArea(int index_num1, int value_num1, int index_num2, int value_num2) {
		return (index_num2 - index_num1) * min(value_num1, value_num2);
	}

	int maxArea1(vector<int>& height) {
		//vector<int> resultSave;
		int ans = 0;
		int n = height.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ans = max(ans, computeArea(i, height[i], j, height[j]));
				//resultSave.push_back(computeArea(i, height[i], j, height[j]));
			}
		}
		//auto maxArea = max_element(resultSave.begin(), resultSave.end());
		//return *maxArea;
		return ans;
	}

	//solution 2: 双指针法，与暴力解法将所有情况全部计算出来不同，双指针法舍去了一下显然不可能的答案，免于计算面积
	//舍弃的思路是，双指针每次移动短的那根，这样就把固定短的，移动长的这一部分的结果直接舍弃了
	int maxArea2(vector<int>& height) {
		int left = 0, right = height.size()-1;
		int ans = 0;
		while (left < right) {
			int area = (right - left) * min(height[left], height[right]);
			ans = max(ans, area);
			if (height[left] <= height[right]) {
				++left;
			}
			else {
				--right;
			}
		}
		return ans;
	}
};
#pragma once
//Given an array nums of n integers and an integer target, find three integers in nums such that 
//the sum is closest to target. Return the sum of the three integers.
//You may assume that each input would have exactly one solution.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: 排序+双指针法，类似于No_15 ，时间复杂度O(n^2)，省略了一些更不可能的计算
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ans, n = nums.size(), error=INT_MAX;
		for (int first = 0; first < n - 2; ++first) {
			int second = first + 1, third = n - 1;
			while (second < third) {
				int sum = nums[first] + nums[second] + nums[third];
				int temp_error = abs(target - sum);
				//比较是不是更接近了
				if (temp_error < error) {
					error = temp_error;
					ans = sum;
				}
				if (sum < target) {
					++second;
				}
				else if (sum > target) {
					--third;
				}
				else 
					return sum;
			}
		}
		return ans;
	}
};
#pragma once
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include<vector>
#include<unordered_map>;
using namespace std;

class Solution {
public:
	//solution 1: 暴力解法
	vector<int> twoSum1(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (nums[i] + nums[j] == target)
					return { i,j };
			}
		}
		return {};
	}

	//solution 2: 哈希表法
	vector<int> twoSum2(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;									//first为数值，second为索引
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);						//在hashtable中查找和当前nums[i]共同满足target条件的数在不在hashtable中
			if (it != hashtable.end()) return { it->second, i };
			hashtable[nums[i]] = i;											//如果没满足return条件，则将nums[i]和i存入hashtable
		}
		return {};
	}

	//solution 3: 排序+双指针法(不能解决返回下标的问题)
	/*
	vector<int> twoSum3(vector<int>& nums, int target) {
		int n = nums.size();
		int start = 0, end = n - 1;
		sort(nums.begin(), nums.end());
		while (start < end) {
			int sum = nums[start] + nums[end];
			if (sum == target) {
				return { nums[start], nums[end] };
			}
			else if (sum < target) {
				++start;
			}
			else {
				--end;
			}
		}
		return {};
	}
	*/
		
};
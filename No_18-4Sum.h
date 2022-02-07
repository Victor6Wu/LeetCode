#pragma once
//Given an array nums of n integers, return an array of all the unique quadruplets 
//[nums[a], nums[b], nums[c], nums[d]] such that:
//0 <= a, b, c, d < n
//a, b, c, and d are distinct.
//nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: 不管外层指针的移动条件设置成何，都会有覆盖不到的情况，无效解
	/*
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		int first = 0, forth = n - 1;
		while (first < forth-2) {
			//判断second前后是否数值相同，相同则没必要进行后续内容，开始下次循环
			if (first > 0 && nums[first] == nums[first - 1]) {
				++first;
				continue;
			}
			//判断third前后是否数值相同，相同则没必要进行后续内容，开始下次循环
			if (forth < n - 1 && nums[forth] == nums[forth + 1]) {
				--forth;
				continue;
			}

			int second = first + 1, third = forth - 1;
			int temp_sum = nums[first] + nums[second] + nums[third] + nums[forth];	//创建一个临时量，用于存储内部双指针最后一次sum的结果，用于确定外部双指针下一步该谁移动
			while (second < third) {	
				int sum = nums[first] + nums[second] + nums[third] + nums[forth];
				if (abs(sum-target) > abs(temp_sum-target)) temp_sum = sum;		//取得最后一次的sum

				//判断second前后是否数值相同，相同则没必要进行后续内容，开始下次循环
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					++second;
					continue;
				}
				//判断third前后是否数值相同，相同则没必要进行后续内容，开始下次循环
				if (third < forth - 1 && nums[third] == nums[third + 1]) {
					--third;
					continue;
				}

				if (sum < target) ++second;
				else if (sum > target) --third;
				else {
					ans.push_back({ nums[first] , nums[second] , nums[third] , nums[forth] });
					++second;
				}
			}

			//根据temp_sum和target的大小关系，确定外部双指针的移动方向
			if (temp_sum <= target)	++first;
			else --forth;
		}
		return ans;
	}*/

	//solution ：排序后，两层循环+双指针，相当于比No_16多了一层外循环
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int first = 0; first < n - 3; ++first) {
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			for (int second = first + 1; second < n - 2; ++second) {
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				int third = second + 1, forth = n - 1;
				while (third < forth) {
					int sum = nums[first] + nums[second] + nums[third] + nums[forth];

					if (third > second + 1 && nums[third] == nums[third - 1]) {
						++third;
						continue;
					}
					//判断third前后是否数值相同，相同则没必要进行后续内容，开始下次循环
					if (forth < n - 1 && nums[forth] == nums[forth + 1]) {
						--forth;
						continue;
					}

					if (sum == target) {
						ans.push_back({ nums[first] , nums[second] , nums[third] , nums[forth] });
						//左右同时收缩
						++third;
						--forth;
					}
					else if (sum < target) {
						++third;
					}
					else {
						--forth;
					}
				}
			}
		}
		return ans;
	}
};
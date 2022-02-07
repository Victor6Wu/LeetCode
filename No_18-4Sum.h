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
	//solution 1: �������ָ����ƶ��������óɺΣ������и��ǲ������������Ч��
	/*
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		int first = 0, forth = n - 1;
		while (first < forth-2) {
			//�ж�secondǰ���Ƿ���ֵ��ͬ����ͬ��û��Ҫ���к������ݣ���ʼ�´�ѭ��
			if (first > 0 && nums[first] == nums[first - 1]) {
				++first;
				continue;
			}
			//�ж�thirdǰ���Ƿ���ֵ��ͬ����ͬ��û��Ҫ���к������ݣ���ʼ�´�ѭ��
			if (forth < n - 1 && nums[forth] == nums[forth + 1]) {
				--forth;
				continue;
			}

			int second = first + 1, third = forth - 1;
			int temp_sum = nums[first] + nums[second] + nums[third] + nums[forth];	//����һ����ʱ�������ڴ洢�ڲ�˫ָ�����һ��sum�Ľ��������ȷ���ⲿ˫ָ����һ����˭�ƶ�
			while (second < third) {	
				int sum = nums[first] + nums[second] + nums[third] + nums[forth];
				if (abs(sum-target) > abs(temp_sum-target)) temp_sum = sum;		//ȡ�����һ�ε�sum

				//�ж�secondǰ���Ƿ���ֵ��ͬ����ͬ��û��Ҫ���к������ݣ���ʼ�´�ѭ��
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					++second;
					continue;
				}
				//�ж�thirdǰ���Ƿ���ֵ��ͬ����ͬ��û��Ҫ���к������ݣ���ʼ�´�ѭ��
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

			//����temp_sum��target�Ĵ�С��ϵ��ȷ���ⲿ˫ָ����ƶ�����
			if (temp_sum <= target)	++first;
			else --forth;
		}
		return ans;
	}*/

	//solution �����������ѭ��+˫ָ�룬�൱�ڱ�No_16����һ����ѭ��
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
					//�ж�thirdǰ���Ƿ���ֵ��ͬ����ͬ��û��Ҫ���к������ݣ���ʼ�´�ѭ��
					if (forth < n - 1 && nums[forth] == nums[forth + 1]) {
						--forth;
						continue;
					}

					if (sum == target) {
						ans.push_back({ nums[first] , nums[second] , nums[third] , nums[forth] });
						//����ͬʱ����
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
#pragma once
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//Notice that the solution set must not contain duplicate triplets.
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: 三层遍历，时间复杂度O(n^3)

	//solution 2: 空间换时间，构建n个哈希表，理论时间复杂度O(n^2),但是时间依旧超时，不可取
	//关于控制重复，在twoSum时要保证有一定的顺序，这样才能在后面确定是否重复
	//可以利用set，在插入的时候就把重复的舍弃；或者采用vector，在插入完毕后，删除重复的
	vector<vector<int>> twoSum(vector<int>& nums, int target) {
		vector<vector<int>> temp1;
		unordered_map<int, int> hashtable;									//first为数值，second为索引
		for (int i = nums.size()-1; i >=0; --i) {
			auto it = hashtable.find(target - nums[i]);						//在hashtable中查找和当前nums[i]共同满足target条件的数在不在hashtable中
			if (it == hashtable.end()) hashtable[nums[i]] = i;				//如果没满足return条件，则将nums[i]和i存入hashtable
			else {
				vector<int> temp = { nums[i], it->first, 0 - target };
				temp1.push_back(temp);
			}
				
		}
		return temp1;		
	}

	vector<vector<int>> threeSum2(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) return {};
		//vector<vector<int>> output;
		unordered_set<vector<int>> result;
		sort(nums.begin(), nums.end());								//要排序，否则后面无法确定重复
		for (int i = n-1; i > 1; --i) {
			int value = nums[i];
			int target = 0 - value;
			nums.pop_back();
			vector<vector<int>> temp = twoSum(nums, target);
			if (!temp.empty()) {
				//output.insert(output.end(), temp.begin(), temp.end());
				result.insert(temp.begin(), temp.end());
			}
		}
		vector<vector<int>> output;
		output.insert(output.end(), result.begin(), result.end());
		//vector方法，删除排序
		//sort(output.begin(), output.end()); //注意，必须先排序
		//output.erase(unique(output.begin(), output.end()), output.end());

		return output;
	}

	//solution 3: 排序+双指针法
	//排序的目的在于给每个结果一定的顺序，这样便于避免重复结果
	vector<vector<int>> threeSum3(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		// 枚举 a
		for (int first = 0; first < n-2; ++first) {
			// 需要和上一次枚举的数不相同
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c 对应的指针初始指向数组的最右端
			int third = n - 1;
			int target = -nums[first];
			// 枚举 b
			for (int second = first + 1; second < third; ++second) {
				// 需要和上一次枚举的数不相同
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// 需要保证 b 的指针在 c 的指针的左侧
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// 如果指针重合，随着 b 后续的增加
				// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
				if (second == third) {
					break;
				}
				if (nums[second] + nums[third] == target) {
					ans.push_back({ nums[first], nums[second], nums[third] });
				}
			}
		}
		return ans;
	}
};
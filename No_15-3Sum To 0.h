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
	//solution 1: ���������ʱ�临�Ӷ�O(n^3)

	//solution 2: �ռ任ʱ�䣬����n����ϣ������ʱ�临�Ӷ�O(n^2),����ʱ�����ɳ�ʱ������ȡ
	//���ڿ����ظ�����twoSumʱҪ��֤��һ����˳�����������ں���ȷ���Ƿ��ظ�
	//��������set���ڲ����ʱ��Ͱ��ظ������������߲���vector���ڲ�����Ϻ�ɾ���ظ���
	vector<vector<int>> twoSum(vector<int>& nums, int target) {
		vector<vector<int>> temp1;
		unordered_map<int, int> hashtable;									//firstΪ��ֵ��secondΪ����
		for (int i = nums.size()-1; i >=0; --i) {
			auto it = hashtable.find(target - nums[i]);						//��hashtable�в��Һ͵�ǰnums[i]��ͬ����target���������ڲ���hashtable��
			if (it == hashtable.end()) hashtable[nums[i]] = i;				//���û����return��������nums[i]��i����hashtable
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
		sort(nums.begin(), nums.end());								//Ҫ���򣬷�������޷�ȷ���ظ�
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
		//vector������ɾ������
		//sort(output.begin(), output.end()); //ע�⣬����������
		//output.erase(unique(output.begin(), output.end()), output.end());

		return output;
	}

	//solution 3: ����+˫ָ�뷨
	//�����Ŀ�����ڸ�ÿ�����һ����˳���������ڱ����ظ����
	vector<vector<int>> threeSum3(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		// ö�� a
		for (int first = 0; first < n-2; ++first) {
			// ��Ҫ����һ��ö�ٵ�������ͬ
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c ��Ӧ��ָ���ʼָ����������Ҷ�
			int third = n - 1;
			int target = -nums[first];
			// ö�� b
			for (int second = first + 1; second < third; ++second) {
				// ��Ҫ����һ��ö�ٵ�������ͬ
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// ��Ҫ��֤ b ��ָ���� c ��ָ������
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// ���ָ���غϣ����� b ����������
				// �Ͳ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
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

//solution 3: ����+˫ָ�뷨�������Ż�
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		// �ҳ�a + b + c = 0
		// a = nums[i], b = nums[left], c = nums[right]
		for (int i = 0; i < nums.size(); i++) {
			// ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ�飬ֱ�ӷ��ؽ���Ϳ�����
			if (nums[i] > 0) {
				return result;
			}
			// ����ȥ�ط���������©��-1,-1,2 �������
			/*
			if (nums[i] == nums[i + 1]) {
				continue;
			}
			*/
			// ��ȷȥ�ط���
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left) {
				// ȥ�ظ��߼�����������0��0��0 �����������ֱ�ӵ��� right<=left �ˣ��Ӷ�©���� 0,0,0 ������Ԫ��
				/*
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;
				*/
				if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				}
				else {
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					// ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮��
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;

					// �ҵ���ʱ��˫ָ��ͬʱ����
					right--;
					left++;
				}
			}

		}
		return result;
	}
};
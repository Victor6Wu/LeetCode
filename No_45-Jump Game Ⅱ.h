//Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Your goal is to reach the last index in the minimum number of jumps.
//You can assume that you can always reach the last index.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:��ǰ��󣬱����ⷨ���ᳬʱ
	vector<int> res;
	void jump_count(vector<int>& nums, int index, int count) {
		if (index == nums.size() - 1) {
			res.push_back(count);
		}
		else if (index > nums.size() - 1) {
			return;
		}
		else {
			for (int i = 1; i <= nums[index]; i++) {
				jump_count(nums, index + i, count + 1);
			}
		}

	}
	int jump1(vector<int>& nums) {
		jump_count(nums, 0, 0);
		sort(res.begin(),res.end());
		return res[0];
	}

	//solution 2:�Ӻ���ǰ�������ᳬʱ
	int dpCount(vector<int>& nums, vector<int>& dp, int index) {			//����dp[index]��ֵ
		if (index == 0) return 0;
		int res = index;
		for (int i = index - 1; i >= 0; i--) {
			if (nums[i] >= index - i) {
				res = min(dpCount(nums, dp, i) + 1, res);
			}
		}
		return res;
	}
	int jump2(vector<int>& nums) {
		vector<int> dp(nums.size(),0);
		return dpCount(nums, dp, nums.size() - 1);
	}

	//solution 3:��ǰ��󣬽�������洢�����sln 1���Ż�����
	int jump3(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		int index = 1;
		while (index < nums.size()) {
			int count = index;
			for (int i = 0; i <= index - 1; i++) {
				if (nums[i] >= index - i) {
					count = min(dp[i], count);
				}
			}
			dp[index] = count + 1;
			index++;
		}
		return dp[nums.size() - 1];
	}

	//solution 4:̰���㷨��ÿһ�����ڿ�����Ծ�ķ�Χ���ҵ���һ����������Զ��λ��,�����������ﵽ֮ǰ���õı߽������һ��
	int jump(vector<int>& nums) {
		int max_far = 0;
		int end_boundary = 0;		//�߽�㣬һ����Χ�ڵ����һ����
		int step = 0;
		for (int i = 0; i < nums.size() - 1; i++) {//��Ȼ���ǰ�����������ʵ��Χ��һ��һ�εĸ���;iֻ��Ҫ���µ������ڶ����㼴��
			max_far = max(max_far, nums[i] + i);
			//Խ����ǰ�ķ�Χ���ִ�߽�
			if (i == end_boundary) {
				end_boundary = max_far;
				step++;
			}
		}
		return step;
	}
};
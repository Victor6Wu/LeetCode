//Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Your goal is to reach the last index in the minimum number of jumps.
//You can assume that you can always reach the last index.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:从前向后，暴力解法，会超时
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

	//solution 2:从后向前迭代，会超时
	int dpCount(vector<int>& nums, vector<int>& dp, int index) {			//计算dp[index]的值
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

	//solution 3:从前向后，借助数组存储结果，sln 1的优化方法
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

	//solution 4:贪心算法，每一步都在可以跳跃的范围内找到下一个能跳的最远的位置,逐个点遍历，达到之前设置的边界就增加一步
	int jump(vector<int>& nums) {
		int max_far = 0;
		int end_boundary = 0;		//边界点，一个范围内的最后一个点
		int step = 0;
		for (int i = 0; i < nums.size() - 1; i++) {//虽然点是挨个遍历，其实范围是一段一段的更新;i只需要更新到倒数第二个点即可
			max_far = max(max_far, nums[i] + i);
			//越过当前的范围，抵达边界
			if (i == end_boundary) {
				end_boundary = max_far;
				step++;
			}
		}
		return step;
	}
};
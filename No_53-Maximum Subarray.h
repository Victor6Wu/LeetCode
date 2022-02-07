//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:贪心算法，当前指针所指元素同之前元素的和小于0，则丢弃当前元素及以前的序列，从下一个重新开始。
	int maxSubArray(vector<int>& nums) {
		//有个关键点，MaxSum要初始为nums[0]，不可以初始化为0，否则遇到全负数数组会出错
		int MaxSum = nums[0], CurrSum = 0;		//维护两个整数，一个表示最终结果，一个表示遍历过程中阶段性的求和结果
		for (int i = 0; i < nums.size(); i++) {
			CurrSum += nums[i];
			MaxSum = max(MaxSum, CurrSum);
			//每当遇到一个负数使得阶段性求和结果变成非正数，那就重新计数
			if (CurrSum <= 0) {
				CurrSum = 0;
			}
		}
		return MaxSum;
	}

	//solution 2:动态规划，参考贪心算法的思想，当出现一个特别小的负数，求和会成为负数，终结之前的连续字符
	int maxSubArray(vector<int>& nums) {
		int pre = 0, maxAns = nums[0];		//pre表示之前的最大子序和
		for (const auto& x : nums) {
			pre = max(pre + x, x);		//每当pre<=0的时候，pre会从当前的x字符重新开始连续
			maxAns = max(maxAns, pre);
		}
		return maxAns;
	}
};
//动态规划
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> dp(nums.size(), 0); // dp[i]表示包括i之前的最大连续子序列和
		dp[0] = nums[0];
		int result = dp[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
			if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
		}
		return result;
	}
};
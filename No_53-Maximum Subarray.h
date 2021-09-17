//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:贪心算法，当前指针所指元素同之前元素的和小于0，则丢弃当前元素及以前的序列，从下一个重新开始。
	int maxSubArray(vector<int>& nums) {
		int MaxSum = nums[0], CurrSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			CurrSum += nums[i];
			MaxSum = max(MaxSum, CurrSum);
			if (CurrSum <= 0) {
				CurrSum = 0;
			}
		}
		return MaxSum;
	}

	//solution 2:动态规划，参考贪心算法的思想，当出现一个特别小的负数，求和会成为负数，终结之前的连续字符
	int maxSubArray(vector<int>& nums) {
		int pre = 0, maxAns = nums[0];
		for (const auto& x : nums) {
			pre = max(pre + x, x);		//每当pre<=0的时候，pre会从当前的x字符重新开始连续
			maxAns = max(maxAns, pre);
		}
		return maxAns;
	}
};
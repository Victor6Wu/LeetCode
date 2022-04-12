//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
#include<vector>
using namespace std;

//本题还是要仔细阅读题目给出的示例，每个数可重复，且不同顺序是不同组合
//动态规划法
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
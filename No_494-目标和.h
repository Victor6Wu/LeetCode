//给你一个整数数组 nums 和一个整数 target 。
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

//思路：本题最终转变成组合总和的问题，从数组中选一些元素使得和刚好等于目标值。left组 = （target + sum）/ 2
//方法1，回溯法，会超时
//方法2，动态规划，注意本题是想知道装满（不是尽可能满）背包的方法（组合）有多少种，所以dp[j]应该表示填满容量j的背包的方法数
//二维数组dp[i][j] = dp[i -1][j] +dp [i - 1][j - nums[i]]
//一维数组dp[j] = dp[j] + dp[j - nums[i]]
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;        //如果target绝对值大于sum，肯定不能找出组合
        if ((target + sum) % 2 == 1) return 0;         //如果（target + sum）是奇数，肯定不能找出组合
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;                              //组合为0只有一种方案
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
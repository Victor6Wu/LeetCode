//给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
#include<vector>
using namespace std;

//完全背包法
//这题需要注意，物品是1-10000中所有的完全平方数，需要创建数组先保持完全平方数，剩下的部分和No_322零钱兑换差不多
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(100);
        for (int i = 0; i < 100; i++) {
            nums[i] = (i + 1) * (i + 1);
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = nums[i]; j <= n; j++) {
                if (dp[j - nums[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1);
                }
            }
        }
        return dp[n];
    }
};

//其实这题可以优化空间复杂度，物品不需要用数组保存，因为[1,10000]中的完全平方数其实是[1, 100]中每个元素的平方
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // 遍历物品
            for (int j = 1; j <= n; j++) { // 遍历背包
                if (j - i * i >= 0) {
                    dp[j] = min(dp[j - i * i] + 1, dp[j]);
                }
            }
        }
        return dp[n];
    }
};
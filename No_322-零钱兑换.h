//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//你可以认为每种硬币的数量是无限的。
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {        //遍历物品
            for (int j = coins[i]; j <= amount; j++) {  //遍历背包
                if (dp[j - coins[i]] <= INT_MAX - 1)    //如果dp[j - coins[i]]是初始值则跳过，因为+1会溢出
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
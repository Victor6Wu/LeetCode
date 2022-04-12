//给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//请你计算并返回达到楼梯顶部的最低花费。
#include<vector>
using namespace std;

//自编代码
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);      //dp[i]表示到达第i个台阶需要的最小花费
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
        }
        return dp[n];
    }
};

//随想录代码，dp[i]表示从i处向上的花费，因此递推公式和返回值和自编代码略有区别
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

//代码优化，空间复杂度
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();      //dp[i]表示到达第i个台阶需要的最小花费
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = min((dp1 + cost[i - 1]), (dp0 + cost[i - 2]));
            dp0 = dp1;
            dp1 = tmp;
        }
        return dp1;
    }
};
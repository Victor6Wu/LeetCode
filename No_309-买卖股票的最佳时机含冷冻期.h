//No_122的基础上多了冷冻期，即卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
#include<vector>
using namespace std;

//动态规划法，主要思考的框架和No_123\188类似，主要是卖出股票的状态分为两类：今天刚刚卖出、之前卖出的过了冷冻期
//0：持有股票状态；1：卖出股票的状态；2：今天卖出股票的状态；3：冷冻期状态
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            //买入状态与卖出相对，会有三种情况
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        //返回的是手上没有股票的状态
        return max(dp[n - 1][3], max(dp[n - 1][2], dp[n - 1][1]));
    }
};

//优化空间复杂度，只用dp[2][4]即可，每次的结果由上一次决定
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            //买入状态与卖出相对，会有三种情况
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][3]) - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][3]);
            dp[i % 2][2] = dp[(i - 1) % 2][0] + prices[i];
            dp[i % 2][3] = dp[(i - 1) % 2][2];
        }
        //返回的是手上没有股票的状态
        return max(dp[(n - 1) % 2][3], max(dp[(n - 1) % 2][2], dp[(n - 1) % 2][1]));
    }
};
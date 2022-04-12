//给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。
//你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。
#include<vector>
using namespace std;

//方法1：贪心法，遍历的过程中记录最低价格，更新最大收益
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            //更新最低价格
            low = min(low, prices[i]);
            //更新收益
            res = max(res, (prices[i] - low));
        }
        return res;
    }
};

//方法2：动态规划，参考代码随想录
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        //dp[i][0]表示第天持有股票手上的钱；dp[i][1]代表不持有
        //钱从第0天开始，起始值是0
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[len - 1][1];
    }
};

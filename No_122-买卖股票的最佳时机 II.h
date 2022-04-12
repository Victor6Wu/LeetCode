//给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
//在每一天，你可能会决定购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
//返回 你能获得的 最大 利润 。
#include<vector>
using namespace std;

//贪心法1，低买高卖，缺点是需要嵌套一层循环
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size();) {
            int j = i;
            while (j + 1 < prices.size() && prices[j] < prices[j + 1]) {
                j++;
            }
            profit += prices[j] - prices[i];
            i = j + 1;
        }
        return profit;
    }
};

//贪心法2，以一天的利润为单位，第一天买第二天就卖，统计所有的正利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};

//方法3：动态规划，与No_121最大的不同是可以交易多次，那么持有股票的最大现金dp[i][0]可能会包括之前的交易所得
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0)); //0表示持有股票；1表示不持有
        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // 注意这里是和121. 买卖股票的最佳时机唯一不同的地方。
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[len - 1][1];
    }
};
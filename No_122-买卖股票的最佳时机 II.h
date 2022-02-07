//给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
//在每一天，你可能会决定购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
//返回 你能获得的 最大 利润 。
#include<vector>
using namespace std;

//贪心法1，低买高卖
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
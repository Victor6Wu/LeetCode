//在No_122的基础上增添了交易手续费，需要考虑交易的时间，而不能拆分成每一天交易
#include<vector>
using namespace std;

//思路仍是贪心，手续费可以视作买股票的成本之一，只要找到有利可图的是否就可以进行交易
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = prices[0] + fee;              //这里将手续费放入买入价格进行考虑
        int profit = 0;     
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {        //遇到更低的价格
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) {         //遇到有利可图时
                profit += prices[i] - buy;

                //这一步非常关键，当卖出一支股票时，就获得了以相同价格并且免除手续费买入一只股票的权利
                //这样做的目的是应对后面股票价格会继续增加的情况，毕竟从贪心的角度来说，这种情况只用交易一次，即付一次手续费
                buy = prices[i];                
            }
        }
        return profit;
    }
};

//动态规划法，在No_122的基础上，卖出的时候增加一个手续费开支就行
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0)); //0表示持有股票；1表示不持有
        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // 注意这里是和121. 买卖股票的最佳时机唯一不同的地方。
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[len - 1][1];
    }
};
//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
#include<vector>
using namespace std;

//贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }
};

//动态规划，
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        //dp0表示持有状态，dp1表示不持有状态
        vector<int> dp0(len, 0), dp1(len, 0);
        dp0[0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp0[i] = max(dp0[i - 1], -prices[i]);       //更新持有状态为更低的价格
            //不持有有两种：之前就不持有；之前持有，本次卖出
            dp1[i] = max(dp1[i - 1], dp0[i - 1] + prices[i]);   //比较本次卖出和之前卖出哪个利润更高
        }
        return dp1[len - 1];
    }
};
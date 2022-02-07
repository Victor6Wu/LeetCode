//在No_122的基础上增添了交易手续费，需要考虑交易的时间，而不能拆分成每一天交易
#include<vector>
using namespace std;

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
                buy = prices[i];
            }
        }
        return profit;
    }
};
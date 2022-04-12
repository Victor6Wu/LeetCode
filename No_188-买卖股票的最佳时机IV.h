//在No_123的基础上，限制交易次数最多k次
#include<vector>
using namespace std;

//在No_123的基础上，将交易两次的思想拓展到k次，因为每次买入或者卖出都取决于前面一个的结果，具有一定的重复性
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k == 0) return 0;
        vector<int> dp(2 * k + 1, 0);
        for (int i = 0; i < k; i++) {
            dp[2 * i + 1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < k; j++) {
                dp[2 * j + 1] = max(dp[2 * j + 1], dp[2 * j] - prices[i]);  //买入
                dp[2 * j + 2] = max(dp[2 * j + 2], dp[2 * j + 1] + prices[i]);//卖出
            }
        }
        return dp[2 * k];
    }
};
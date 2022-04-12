//No_122�Ļ����ϣ������˽��״������������
#include<vector>
#include<queue>
using namespace std;

// �汾һ
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};

// �汾��
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> dp(5, 0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return dp[4];
    }
};

//�Ա���룬��������[6,1,3,2,4,7]��Ԥ�ڽ��7������6
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size() - 1);
        for (int i = 1; i < prices.size(); i++) {
            profit[i - 1] = prices[i] - prices[i - 1];
        }
        
        priority_queue<int> max_profit;
        int first = 0;
        while (first < profit.size()) {
            while (first < profit.size() && profit[first] <= 0) {       //����������
                first++;
            }
            if (first >= profit.size()) break;
            int tmp_sum = profit[first];
            int tmp_max = profit[first++];
            while (first < profit.size() && tmp_sum > 0) {
                tmp_sum += profit[first++];
                tmp_max = max(tmp_max, tmp_sum);
            }
            //��¼���ε�����������е����ֵ
            max_profit.push(tmp_max);
        }

        //ȡ������������
        int ans = 0;
        for (int i = 1; i <= 2; i++) {
            if (!max_profit.empty()) {
                ans += max_profit.top();
                max_profit.pop();
            }
        }
        return ans;
    }
};
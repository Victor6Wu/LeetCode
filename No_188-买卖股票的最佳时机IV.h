//��No_123�Ļ����ϣ����ƽ��״������k��
#include<vector>
using namespace std;

//��No_123�Ļ����ϣ����������ε�˼����չ��k�Σ���Ϊÿ���������������ȡ����ǰ��һ���Ľ��������һ�����ظ���
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
                dp[2 * j + 1] = max(dp[2 * j + 1], dp[2 * j] - prices[i]);  //����
                dp[2 * j + 2] = max(dp[2 * j + 2], dp[2 * j + 1] + prices[i]);//����
            }
        }
        return dp[2 * k];
    }
};
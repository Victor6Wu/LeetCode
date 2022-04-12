//No_122�Ļ����϶����䶳�ڣ���������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
#include<vector>
using namespace std;

//��̬�滮������Ҫ˼���Ŀ�ܺ�No_123\188���ƣ���Ҫ��������Ʊ��״̬��Ϊ���ࣺ����ո�������֮ǰ�����Ĺ����䶳��
//0�����й�Ʊ״̬��1��������Ʊ��״̬��2������������Ʊ��״̬��3���䶳��״̬
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            //����״̬��������ԣ������������
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        //���ص�������û�й�Ʊ��״̬
        return max(dp[n - 1][3], max(dp[n - 1][2], dp[n - 1][1]));
    }
};

//�Ż��ռ临�Ӷȣ�ֻ��dp[2][4]���ɣ�ÿ�εĽ������һ�ξ���
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            //����״̬��������ԣ������������
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][3]) - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][3]);
            dp[i % 2][2] = dp[(i - 1) % 2][0] + prices[i];
            dp[i % 2][3] = dp[(i - 1) % 2][2];
        }
        //���ص�������û�й�Ʊ��״̬
        return max(dp[(n - 1) % 2][3], max(dp[(n - 1) % 2][2], dp[(n - 1) % 2][1]));
    }
};
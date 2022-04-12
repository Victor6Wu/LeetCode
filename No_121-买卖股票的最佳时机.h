//����һ������ `prices` �����ĵ� `i` ��Ԫ�� `prices[i]` ��ʾһ֧������Ʊ�� `i` ��ļ۸�
//��ֻ��ѡ�� **ĳһ��** ������ֻ��Ʊ����ѡ���� **δ����ĳһ����ͬ������** �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������
//��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� `0` ��
#include<vector>
using namespace std;

//����1��̰�ķ��������Ĺ����м�¼��ͼ۸񣬸����������
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            //������ͼ۸�
            low = min(low, prices[i]);
            //��������
            res = max(res, (prices[i] - low));
        }
        return res;
    }
};

//����2����̬�滮���ο���������¼
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        //dp[i][0]��ʾ������й�Ʊ���ϵ�Ǯ��dp[i][1]��������
        //Ǯ�ӵ�0�쿪ʼ����ʼֵ��0
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[len - 1][1];
    }
};

//�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�
#include<vector>
using namespace std;

//̰���㷨
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

//��̬�滮��
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        //dp0��ʾ����״̬��dp1��ʾ������״̬
        vector<int> dp0(len, 0), dp1(len, 0);
        dp0[0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp0[i] = max(dp0[i - 1], -prices[i]);       //���³���״̬Ϊ���͵ļ۸�
            //�����������֣�֮ǰ�Ͳ����У�֮ǰ���У���������
            dp1[i] = max(dp1[i - 1], dp0[i - 1] + prices[i]);   //�Ƚϱ���������֮ǰ�����ĸ��������
        }
        return dp1[len - 1];
    }
};
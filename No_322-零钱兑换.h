//����һ���������� coins ����ʾ��ͬ����Ӳ�ң��Լ�һ������ amount ����ʾ�ܽ�
//���㲢���ؿ��Դճ��ܽ������� ���ٵ�Ӳ�Ҹ��� �����û���κ�һ��Ӳ�����������ܽ����� -1 ��
//�������Ϊÿ��Ӳ�ҵ����������޵ġ�
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {        //������Ʒ
            for (int j = coins[i]; j <= amount; j++) {  //��������
                if (dp[j - coins[i]] <= INT_MAX - 1)    //���dp[j - coins[i]]�ǳ�ʼֵ����������Ϊ+1�����
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
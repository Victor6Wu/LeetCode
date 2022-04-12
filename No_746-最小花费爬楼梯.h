//����һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�
//�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�
//������㲢���شﵽ¥�ݶ�������ͻ��ѡ�
#include<vector>
using namespace std;

//�Ա����
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);      //dp[i]��ʾ�����i��̨����Ҫ����С����
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
        }
        return dp[n];
    }
};

//����¼���룬dp[i]��ʾ��i�����ϵĻ��ѣ���˵��ƹ�ʽ�ͷ���ֵ���Ա������������
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // ע�����һ���������Ϊ���û��ѣ�����ȡ������һ�����ڶ���������ֵ
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

//�����Ż����ռ临�Ӷ�
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();      //dp[i]��ʾ�����i��̨����Ҫ����С����
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = min((dp1 + cost[i - 1]), (dp0 + cost[i - 2]));
            dp0 = dp1;
            dp1 = tmp;
        }
        return dp1;
    }
};
#include<vector>
using namespace std;

//��̬�滮��
//��ϸ�۲�n��n-1���������Կ��Է��֣�
//1.���鳤��Ϊ5 * n - 1
//2.�׿�������̸����ֵ����˵dp1[i] = sum(dp0[i - j]) * 1 / 6.0������jΪ1~6
//3.������Ԫ���ɺ�Ϊn��dp0��dp1����Ԫ���ϸպ����1
//4.�ѵ��������úñ߽�������Ҫ��֤�Ҷ���Щ����dp1[i]��Ԫ�أ��Ȳ��ܶ�Ҳ������
class Solution1 {
public:
    vector<double> dicesProbability(int N) {
        vector<double> dp0(5 * N + 1, 1.0 / 6); //��������ĳ��Ȼ�ﵽ5 * N + 1������ֱ������Ϊ��ô��������ֻҪע�����������Χ����
        if (N == 1) return dp0;
        vector<double> dp1(5 * N + 1, 1.0 / 6);
        double k = 1.0 / 6;
        for (int n = 2; n <= N; n++) {      //��ǰ���Ӹ���
            for (int i = 0; i < 5 * n + 1; i++) {       //��˳����䵱ǰ���Ӹ�����Ӧ�����飬Ҫ����������Χ
                double tmp = 0;
                //�ۼƵ�ǰ������ֵΪ1~6ʱdp0��Ӧ�Ľ��
                for (int j = 1; j <= 6; j++) {

                    //����������ǳ���Ҫ��dp0��ʾ����n-1�����ӵĽ����Ҫ�����������䷶Χ�ڣ�����
                    if (i - j + 1 >= 0 && i - j + 1 < 5 * (n - 1) + 1)  //n�����ӵ���Ԫ��ֵ��n-1�����ӵ���Ԫ�ش�1����������и�+1
                        tmp += dp0[i - j + 1];
                }

                dp1[i] = k * tmp;
            }

            //for (int k = 0; k < 5 * n + 1; k++) dp0[k] = dp1[k];
            dp0.assign(dp1.begin(), dp1.end());
            
        }
        return dp0;
    }
};

//д��2���Ե�������⣬��������Ҫ��д��1����������Խ������
class Solution2 {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6.0);
        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); j++) {       //������һ�������ÿ����
                for (int k = 0; k < 6; k++) {           //������Ͽ��Լ���1��2��3��4��5��6
                    tmp[j + k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};
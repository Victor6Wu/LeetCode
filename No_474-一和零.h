//����һ���������ַ������� strs ���������� m �� n ��
//�����ҳ������� strs ������Ӽ��ĳ��ȣ����Ӽ��� ��� �� m �� 0 �� n �� 1 ��
#include<vector>
#include<string>
using namespace std;

//��̬�滮��
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int oneNum = 0, zeroNum = 0;
            //ͬһ0��1�������൱����Ʒ����
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            //��ѭ��
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);      //ǰ���ǲ����ǵ�ǰstr�������ǿ��ǵ�ǰstr
                }
            }
        }
        return dp[m][n];
    }
};
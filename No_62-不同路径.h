//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����������ÿ��ֻ�����»��������ƶ�һ����
//��������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� �������ܹ��ж�������ͬ��·����
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

//��̬�滮��
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j]��ʾ�ﵽ(i,j)��·���ĸ���
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//���۷���ʵ������������⣬��m + n - 2������ѡ��m - 1����������ϵ�ʱ��Ҫ��ֹ����int�������� ���Բ��ܰ���ʽ�ķ��Ӷ����������ĸ�����������������������ѭ����ֱ�Ӵ���
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1; // ����
        int denominator = m - 1; // ��ĸ
        int count = m - 1;
        int t = m + n - 2;
        while (count--) {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};
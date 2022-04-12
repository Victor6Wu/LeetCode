//����һ������ n ������ ��Ϊ n ����ȫƽ�������������� ��
//��ȫƽ���� ��һ����������ֵ������һ��������ƽ�������仰˵����ֵ����һ�������Գ˵Ļ������磬1��4��9 �� 16 ������ȫƽ�������� 3 �� 11 ���ǡ�
#include<vector>
using namespace std;

//��ȫ������
//������Ҫע�⣬��Ʒ��1-10000�����е���ȫƽ��������Ҫ���������ȱ�����ȫƽ������ʣ�µĲ��ֺ�No_322��Ǯ�һ����
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(100);
        for (int i = 0; i < 100; i++) {
            nums[i] = (i + 1) * (i + 1);
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = nums[i]; j <= n; j++) {
                if (dp[j - nums[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1);
                }
            }
        }
        return dp[n];
    }
};

//��ʵ��������Ż��ռ临�Ӷȣ���Ʒ����Ҫ�����鱣�棬��Ϊ[1,10000]�е���ȫƽ������ʵ��[1, 100]��ÿ��Ԫ�ص�ƽ��
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // ������Ʒ
            for (int j = 1; j <= n; j++) { // ��������
                if (j - i * i >= 0) {
                    dp[j] = min(dp[j - i * i] + 1, dp[j]);
                }
            }
        }
        return dp[n];
    }
};
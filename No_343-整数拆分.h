//����һ�������� n ��������Ϊ k �� ������ �ĺͣ� k >= 2 ������ʹ��Щ�����ĳ˻���󻯡�
//��������Ի�õ����˻� ��
#include<algorithm>
using namespace std;

//���ݷ����Ա���룬��n��΢��һ���ʱ��ͻᳬʱ�����˵����ָ���˻��ֵ�������������û��ݷ����
class Solution1 {
public:
    int acc = 0;
    void backtracking(int tmpRes, int a, int b, int n) {   //a��ʾ���β�ֳ�������b��ʾʣ��ɲ�ֵ���    
        if (b < n)  acc = max(acc, tmpRes * a * b);     //����b�����л��֣�����Ҫ��֤ʣ���b�Ѿ��ȳ�ʼ��nС�ˣ�������Ϊ������ݺ�����ʱ��b�Ǵ�n��ʼ��
        //��b��������
        for (int i = 1; i < b; i++) {
            backtracking(tmpRes * a, i, b - i, n);
        }
    }

    int integerBreak(int n) {
        //tmpRes��ʾ�׶��Եĳ˻����
        int tmpRes = 1;
        backtracking(tmpRes, 1, n, n);
        return acc;
    }
};

//��̬�滮��
class Solution2 {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);  //ע������Ĵ�С
        dp[2] = 1;      //��dp[2]��ʼ��ʼ��
        for (int i = 3; i <= n; i++) {      //ע��ѭ������ʼ����ֹ��Χ����Ϊdp�Ǵ�2��ʼ��ʼ���ģ�����Ҫ�����õ�dp[0]��dp[1]
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
//���ǰ�ֻ���������� 2��3 �� 5 ��������������Ugly Number�����󰴴�С�����˳��ĵ� n ��������
//ͬlc-264
#include<vector>
using namespace std;

//solution 1:��������������ʱ
class Solution1 {
public:
    bool isUglyNumber(int i) {
        if (i <= 0) return false;
        if (i == 1) return true;
        while (i % 2 == 0) {
            i = i / 2;
        }
        while (i % 3 == 0) {
            i = i / 3;
        }
        while (i % 5 == 0) {
            i = i / 5;
        }
        if (i == 1) {
            return true;
        }
        else return false;
    }
    int nthUglyNumber(int n) {
        int i = 1;
        for (; i < INT_MAX; i++) {
            if (isUglyNumber(i) == true) {
                n--;
            }
            if (n == 0) return i;
        }
        return 0;
    }
};

//��̬�滮1��Ҳ�ᳬʱ
class Solution2 {
public:
    int nthUglyNumber(int n) {
        if (n <= 1) return n;
        vector<bool> dp(INT_MAX, false);
        int count = 1;
        int ans = 1;
        dp[0] = true;
        dp[1] = true;
        //i�������������ô������i/2��i/3��i/5
        for (int i = 2; i < INT_MAX; i++) {
            if (i % 2 == 0 && dp[i / 2]) {
                dp[i] = dp[i / 2];
                count++;
            }
            else if (i % 3 == 0 && dp[i / 3]) {
                dp[i] = dp[i / 3];
                count++;
            }
            else if (i % 5 == 0 && dp[i / 5]) {
                dp[i] = dp[i / 5];
                count++;
            }

            if (count == n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

//��̬�滮2������ĳ�����ʵ����ǰ��ĳ�����2��3��5��ֻ����Ҫ����ʵ�ʵĴ�С˳��������
//������ָ�뷨����ָ���ֵ�ֱ��2��3��5��ȡ������С�ģ�ָ��+1
class Solution3 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num1 = dp[p2] * 2;
            int num2 = dp[p3] * 3;
            int num3 = dp[p5] * 5;
            dp[i] = min(num1, min(num2, num3));
            if (dp[i] == num1) p2++;
            if (dp[i] == num2) p3++;
            if (dp[i] == num3) p5++;
        }
        return dp[n];
    }
};
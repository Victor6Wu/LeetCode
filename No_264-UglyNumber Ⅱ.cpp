//Given an integer n, return the nth ugly number.
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    //solution 1:������
    bool isUglyNumber1(int i) {
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
    int nthUglyNumber1(int n) {
        int i = 1;
        for (; i < INT_MAX; i++) {
            if (isUglyNumber1(i) == true ) {
                n--;
            }
            if (n == 0) return i;
        }
        return 0;
    }

    //solution 2:����set������ĳ���ʵ����ǰ��ĳ�������2��3��5�����ÿ��ȡ����ǰ��С������ϵ���������
    int nthUglyNumber2(int n) {
        long long ans;
        set<long long> q;
        q.insert(1);
        while (n > 1) {
            auto it = q.begin();
            ans = *it;
            if((ans * 2) < INT_MAX) q.insert(ans * 2);
            if((ans * 3) < INT_MAX) q.insert(ans * 3);
            if((ans * 5) < INT_MAX) q.insert(ans * 5);
            q.erase(ans);
            n--;
        }
        return *q.begin();
    }

    //��̬�滮����
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;     //��������ָ�룬��ָ�����Ҫ�ֱ��2��3��5
        for(int i=2;i<=n;i++){      //�ӵڶ���������ʼ��
            int num2 = dp[p2] * 2; int num3 = dp[p3] * 3; int num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            //�������Ľ����ȷ�����ĸ�ָ������ƶ�һλ
            if (dp[i] == num2) p2++;
            if (dp[i] == num3) p3++;
            if (dp[i] == num5) p5++;
        }
        return dp[n];
    }
};
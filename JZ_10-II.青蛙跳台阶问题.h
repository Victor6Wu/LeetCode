//��̨�ף�����쳲��������У�ֻ�ǳ�ʼ������̫һ��
class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 1;
        int MOD = 1000000007;
        int cur, first = 1, second = 1;
        for (int i = 2; i <= n; i++) {
            cur = (first + second) % MOD;
            second = first;
            first = cur;
        }
        return first;
    }
};
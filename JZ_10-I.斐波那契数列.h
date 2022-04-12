//ʵ��fib����
//ע�ⷵ�صĽ����Ҫȡģ1e9+7��1000000007��


//��Ҫ�ù�������ʵ�֣����鶯̬���ݻ����
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        int MOD = 1000000007;
        int cur, first = 1, second = 0;
        for (int i = 2; i <= n; i++) {
            cur = (first + second) % MOD;
            second = first;
            first = cur;
        }
        return first;
    }
};
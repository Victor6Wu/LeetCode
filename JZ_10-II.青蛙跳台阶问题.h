//跳台阶，近似斐波那契数列，只是初始条件不太一样
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
//实现fib函数
//注意返回的结果需要取模1e9+7（1000000007）


//需要用滚动数组实现，否组动态数据会过大；
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
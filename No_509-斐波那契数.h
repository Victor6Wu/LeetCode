//F(0) = 0，F(1) = 1 F(n) = F(n - 1) + F(n - 2)，其中 n > 1 给你n ，请计算 F(n) 。
#include<vector>
using namespace std;

//递归法
class Solution1 {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};

//动态规划法
class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};

//动态规划法代码改进，空间复杂度可以降低为O(1)
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(2);
        dp[0] = 0;          //用于表示F(n-2)
        dp[1] = 1;          //表示F(n-1)
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            //更新dp
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
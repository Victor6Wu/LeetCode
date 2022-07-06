//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
//请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
#include<vector>
#include<algorithm>
using namespace std;

//错误答案
class Solution {
public:
    int cuttingRope(int n) {
        int base = sqrt(n);
        int count = n / base;
        int extra = n % base;
        int ans = pow(base, count - 1);
        ans *= (base + extra);
        return ans;
    }
};

//方法1：数学推导，结论：尽可能分成长度为3的段
//1.尽可能按照长度3来切分，余0、1、2
//2.余0不用考虑；余1：3+1=2+2，但是3*1<2*2，所以拆分成2 + 2的形式；余2:5>3*2，所以就按照3 + 2
//3.对于绳子长队<=3的情况，根据题意单独考虑即可
class Solution1 {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int count = n / 3;
        int remain = n % 3;
        int ans;
        if (remain == 0) ans = pow(3, count);
        else if (remain == 1) {
            ans = pow(3, count - 1);
            ans *= 4;
        }
        else {
            ans = pow(3, count) * 2;
        }
        return ans;
    }
};

//方法2：动态规划，时间复杂度O(N^2)
//长度为i的绳子，剪成j、i - j，乘积有两种可能：j*(i-j)、j*dp[i - j]，取最大即可
//j从2遍历即可，因为减去长度1对乘积没有任何贡献，到i为止，因为至少分成2段
class Solution2 {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));    //记得dp[i]也要参与转移方程，因为j的大小在变化
            }
            
        }
        return dp[n];
    }
};
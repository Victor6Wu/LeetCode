//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//返回你可以获得的最大乘积 。
#include<algorithm>
using namespace std;

//回溯法，自编代码，当n稍微大一点的时候就会超时。如果说本题指定了划分的数量，则可以用回溯法解答
class Solution1 {
public:
    int acc = 0;
    void backtracking(int tmpRes, int a, int b, int n) {   //a表示本次拆分出的数，b表示剩余可拆分的数    
        if (b < n)  acc = max(acc, tmpRes * a * b);     //对于b不进行划分，但是要保证剩余的b已经比初始的n小了，这是因为进入回溯函数的时候b是从n开始的
        //对b继续划分
        for (int i = 1; i < b; i++) {
            backtracking(tmpRes * a, i, b - i, n);
        }
    }

    int integerBreak(int n) {
        //tmpRes表示阶段性的乘积结果
        int tmpRes = 1;
        backtracking(tmpRes, 1, n, n);
        return acc;
    }
};

//动态规划法
class Solution2 {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);  //注意数组的大小
        dp[2] = 1;      //从dp[2]开始初始化
        for (int i = 3; i <= n; i++) {      //注意循环的起始和终止范围，因为dp是从2开始初始化的，所以要避免用到dp[0]和dp[1]
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
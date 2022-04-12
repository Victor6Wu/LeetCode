//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。机器人每次只能向下或者向右移动一步。
//机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。问总共有多少条不同的路径？
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

//动态规划法
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j]表示达到(i,j)处路径的个数
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//数论法，实际是求组合问题，（m + n - 2）个数选择（m - 1）个；求组合的时候，要防止两个int相乘溢出！ 所以不能把算式的分子都算出来，分母都算出来再做除法，而是在循环中直接处理
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--) {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};
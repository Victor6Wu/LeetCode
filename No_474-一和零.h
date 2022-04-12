//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
#include<vector>
#include<string>
using namespace std;

//动态规划法
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int oneNum = 0, zeroNum = 0;
            //同一0、1数量，相当于物品重量
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            //内循环
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);      //前者是不考虑当前str，后者是考虑当前str
                }
            }
        }
        return dp[m][n];
    }
};
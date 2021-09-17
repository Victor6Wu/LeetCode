//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//	'?' Matches any single character.
//	'*' Matches any sequence of characters(including the empty sequence).
//The matching should cover the entire input string (not partial).
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:动态规划,dp[i][j]表示s的前i个字符和p的前j个字符的匹配情况;时间和空间复杂度O(MN)
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));	//构建动态数组，最终结果要看dp[m][n]
		//确定边界,默认false
		dp[0][0] = true;
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') {
				dp[0][j] = true;
			}
			else {
				break;		//出现不是连续*的时候，就停止设置true
			}
		}

		//动态规划
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
				}
				else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}

	//solution 2:贪心算法（暴力解法），用 * 将p分割为一个个子串，分别对子串进行暴力匹配

};
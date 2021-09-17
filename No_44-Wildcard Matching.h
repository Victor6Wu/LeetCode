//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//	'?' Matches any single character.
//	'*' Matches any sequence of characters(including the empty sequence).
//The matching should cover the entire input string (not partial).
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:��̬�滮,dp[i][j]��ʾs��ǰi���ַ���p��ǰj���ַ���ƥ�����;ʱ��Ϳռ临�Ӷ�O(MN)
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));	//������̬���飬���ս��Ҫ��dp[m][n]
		//ȷ���߽�,Ĭ��false
		dp[0][0] = true;
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') {
				dp[0][j] = true;
			}
			else {
				break;		//���ֲ�������*��ʱ�򣬾�ֹͣ����true
			}
		}

		//��̬�滮
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

	//solution 2:̰���㷨�������ⷨ������ * ��p�ָ�Ϊһ�����Ӵ����ֱ���Ӵ����б���ƥ��

};
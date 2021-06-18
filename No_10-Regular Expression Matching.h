//Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:动态规划法
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		//构造比较函数
		auto matches = [&](int i, int j) {		//此处i,j表示第几个
			if (i == 0) {
				return false;
			}
			if (p[j - 1] == '.') {
				return true;
			}
			return s[i - 1] == p[j - 1];	//真正比较的对象
		};
		//创建数组，存储前i,j个字符的匹配情况
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1));		//要多出一个维度,引入第0个字符
		f[0][0] = true;
		for (int i = 0; i <= m; ++i) {		//i必须从0开始，将[0][j]全部填充为false
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					f[i][j] = f[i][j - 2];
					//如果匹配，则多一个选择
					if (matches(i, j - 1)) {
						f[i][j] = f[i][j - 2] || f[i - 1][j];
					}
				}
				else {
					if (matches(i, j)) {
						f[i][j] = f[i - 1][j - 1];
					}
				}
			}
		}
		return f[m][n];
	}
};

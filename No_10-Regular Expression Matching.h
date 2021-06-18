//Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:��̬�滮��
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		//����ȽϺ���
		auto matches = [&](int i, int j) {		//�˴�i,j��ʾ�ڼ���
			if (i == 0) {
				return false;
			}
			if (p[j - 1] == '.') {
				return true;
			}
			return s[i - 1] == p[j - 1];	//�����ȽϵĶ���
		};
		//�������飬�洢ǰi,j���ַ���ƥ�����
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1));		//Ҫ���һ��ά��,�����0���ַ�
		f[0][0] = true;
		for (int i = 0; i <= m; ++i) {		//i�����0��ʼ����[0][j]ȫ�����Ϊfalse
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					f[i][j] = f[i][j - 2];
					//���ƥ�䣬���һ��ѡ��
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

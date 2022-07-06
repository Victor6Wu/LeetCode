//�ο�lc-10
#include<string>
#include<vector>
using namespace std;

//������룬���ǿ���ͨ���󲿷ֵĲ�������
class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size();
		int bounder = p.size() - n;
		int index = 0;
		while (index <= bounder) {
			string temp = p.substr(index, index + n);
			bool signal = true;
			int i = 0;
			while (i < n) {
				if (temp[i] == '.') {
					++i;
					continue;
				}

				else if (temp[i] == '*') {
					if (i == 0) {
						signal = false;
						break;
					}
					else {
						temp[i] = temp[i - 1];
						continue;
					}
				}
				if (s[i] != temp[i]) {
					signal = false;
					break;
				}
				++i;
			}
			if (signal == true) return true;
			else index++;
		}
		return false;
	}
};

//��̬�滮��
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
		//i��j��ʾ��ǰi��j���ַ�
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
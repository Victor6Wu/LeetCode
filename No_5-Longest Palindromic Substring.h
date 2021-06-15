//Given a string s, return the longest palindromic substring in s.

#include<string>
using namespace std;

class Solution {
public:
	//solution 1:�����ⷨ��ö�����г��ȴ���2���Ӵ�������ж��Ƿ�Ϊ�����ַ�
	string longestPalindrome1(string s) {
		int len = s.length();
		if (len < 2) {
			return s;
		}

		int maxLen = 1, begin = 0;
		for (int strlen = 2; strlen <= len; ++strlen) {				//���ȴ�2��ʼ��֤���ɣ�1��ʱ��������֤
			for (int ptr = 0; ptr + strlen - 1 < len; ptr++) {
				if (validPalindrome(s,ptr,strlen) == true) {		//��֤�Ƿ�Ϊ�����ַ�
					begin = ptr;									//��¼����λ�úͳ���
					maxLen = strlen;
					break;											//�˳���ǰ�ַ������ȵ�ѭ����
				}
			}
		}
		return s.substr(begin, maxLen);
	}

	//��֤�Ƿ�Ϊ�����ַ�������������ַ���+��ʼλ��+����
	bool validPalindrome(string &s, int ptr, int strLen) {
		int left = ptr;
		int right = left + strLen - 1;
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			++left;
			--right;
		}
		return true;
	}

	//solution 2����̬�滮�����ؼ�˼·��һ�������ַ���ȥ�����˵��ַ����м���Ȼ�ǻ����ַ���
	string longestPalindrome2(string s) {
		int len = s.length();
		if (len < 2) {
			return s;
		}
		//������ʼ����
		vector<vector<int>> dp(len, vector<int>(len));
		int begin = 0, maxLen = 1;
		//dp[i][j]��ʾs[i...j]�Ƿ�����ַ���0Ϊ��1Ϊ�ǣ��Ƚ��Խ���Ԫ����Ϊ1
		for (int i = 0; i < len; ++i) {
			dp[i][i] = 1;
		}
		//��ʼ�ݹ�
		//��ö�ٳ��ȵķ�ʽ����
		for (int L = 2; L <= len; ++L) {
			for (int i = 0; i < len; ++i) {
				int j = i + L - 1;
				if (j >= len) break;
				//��ʼ�ж��Ƿ�����ַ���
				if (s[i] != s[j]) {
					dp[i][j] = 0;
				}
				else {
					if (L <= 3) dp[i][j] = 1;		//�жϴ�ʱ�ַ��������Ƿ����3����������ڣ���Ȼ�ǻ����ַ���
					else {
						dp[i][j] = dp[i + 1][j - 1];	//���ȴ���3����Ҫ����ȥ�����˵��ַ����Ƿ�Ϊ�����ַ���
					}
				}
				//�ж��Ƿ�����������ַ�������ʼ��ͳ���
				if (dp[i][j] && L > maxLen) {
					begin = i;
					maxLen = L;
				}
			}
		}
		return s.substr(begin, maxLen);
	}

	//solution 3:������չ����ö���������ģ�������չ
	string longestPalindrome3(string s) {
		int n = s.length();
		if (n < 2) return s;
		//ѭ���ַ�����ÿ��������Ϊ���ĵ�λ�ã�������left��rightȷ��
		int begin = 0, Maxlen = 1;
		for (int i = 0; i + 1 < n; i++) {			//���һ���ַ�����չ��ȫ���Ժ��Ե�
			int len1 = expandCenter(s, i, i);
			int len2 = expandCenter(s, i, i + 1);
			int len = max(len1, len2);
			//����������Ӵ�
			if (len > Maxlen) {
				begin = i - (len - 1) / 2;
				Maxlen = len;
			}
		}
		return s.substr(begin, Maxlen);
	}
	//������չ�������������һ�λ����ַ���λ�úͳ���
	int expandCenter(string& s, int left, int right) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			--left;
			++right;
		}
		return right - left - 1;
	}

	//solution 4:Manacher����̫����
	int expand(const string& s, int left, int right) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return (right - left - 2) / 2;
	}

	string longestPalindrome(string s) {
		int start = 0, end = -1;
		string t = "#";
		for (char c : s) {
			t += c;
			t += '#';
		}
		t += '#';
		s = t;

		vector<int> arm_len;
		int right = -1, j = -1;
		for (int i = 0; i < s.size(); ++i) {
			int cur_arm_len;
			if (right >= i) {
				int i_sym = j * 2 - i;
				int min_arm_len = min(arm_len[i_sym], right - i);
				cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
			}
			else {
				cur_arm_len = expand(s, i, i);
			}
			arm_len.push_back(cur_arm_len);
			if (i + cur_arm_len > right) {
				j = i;
				right = i + cur_arm_len;
			}
			if (cur_arm_len * 2 + 1 > end - start) {
				start = i - cur_arm_len;
				end = i + cur_arm_len;
			}
		}

		string ans;
		for (int i = start; i <= end; ++i) {
			if (s[i] != '#') {
				ans += s[i];
			}
		}
		return ans;
	}
};
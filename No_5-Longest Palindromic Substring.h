//Given a string s, return the longest palindromic substring in s.

#include<string>
using namespace std;

class Solution {
public:
	//solution 1:暴力解法，枚举所有长度大于2的子串，逐个判断是否为回文字符
	string longestPalindrome1(string s) {
		int len = s.length();
		if (len < 2) {
			return s;
		}

		int maxLen = 1, begin = 0;
		for (int strlen = 2; strlen <= len; ++strlen) {				//长度从2开始验证即可，1的时候无需验证
			for (int ptr = 0; ptr + strlen - 1 < len; ptr++) {
				if (validPalindrome(s,ptr,strlen) == true) {		//验证是否为回文字符
					begin = ptr;									//记录索引位置和长度
					maxLen = strlen;
					break;											//退出当前字符串长度的循环，
				}
			}
		}
		return s.substr(begin, maxLen);
	}

	//验证是否为回文字符串，输入的是字符串+起始位置+长度
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

	//solution 2：动态规划法，关键思路：一个回文字符串去掉两端的字符，中间仍然是回文字符串
	string longestPalindrome2(string s) {
		int len = s.length();
		if (len < 2) {
			return s;
		}
		//构建初始变量
		vector<vector<int>> dp(len, vector<int>(len));
		int begin = 0, maxLen = 1;
		//dp[i][j]表示s[i...j]是否回文字符，0为否，1为是；先将对角线元素置为1
		for (int i = 0; i < len; ++i) {
			dp[i][i] = 1;
		}
		//开始递归
		//以枚举长度的方式进行
		for (int L = 2; L <= len; ++L) {
			for (int i = 0; i < len; ++i) {
				int j = i + L - 1;
				if (j >= len) break;
				//开始判断是否回文字符串
				if (s[i] != s[j]) {
					dp[i][j] = 0;
				}
				else {
					if (L <= 3) dp[i][j] = 1;		//判断此时字符串长度是否大于3，如果不大于，必然是回文字符串
					else {
						dp[i][j] = dp[i + 1][j - 1];	//长度大于3，需要考虑去除两端的字符串是否为回文字符串
					}
				}
				//判断是否更新最大回文字符串的起始点和长度
				if (dp[i][j] && L > maxLen) {
					begin = i;
					maxLen = L;
				}
			}
		}
		return s.substr(begin, maxLen);
	}

	//solution 3:中心扩展法，枚举所有中心，尝试扩展
	string longestPalindrome3(string s) {
		int n = s.length();
		if (n < 2) return s;
		//循环字符串的每个可以作为中心的位置，中新用left和right确定
		int begin = 0, Maxlen = 1;
		for (int i = 0; i + 1 < n; i++) {			//最后一个字符的拓展完全可以忽略掉
			int len1 = expandCenter(s, i, i);
			int len2 = expandCenter(s, i, i + 1);
			int len = max(len1, len2);
			//更新最长回文子串
			if (len > Maxlen) {
				begin = i - (len - 1) / 2;
				Maxlen = len;
			}
		}
		return s.substr(begin, Maxlen);
	}
	//中心拓展函数，返回最后一次回文字符的位置和长度
	int expandCenter(string& s, int left, int right) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			--left;
			++right;
		}
		return right - left - 1;
	}

	//solution 4:Manacher法，太难了
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
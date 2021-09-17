//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	//solution 1:�����ⷨ����s�а����ļ��������ַ��������жϣ��ȴӳ���Ϊs.length�����ִ���ʼ��ֱ���ҵ��򡰡�Ϊֹ

	//solution 2:�Ա���룬ʱ�临�Ӷ�O(N^2)
	int longestValidParentheses2(string s) {
		int ans = 0;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			int j = i;
			int countLeft = 0, countRight = 0;
			while (j < len && countLeft >= countRight) {
				if (s[j] == '(') {
					countLeft++;
				}
				else if (s[j] == ')') {
					countRight++;
				}

				if (countLeft == countRight) {
					ans = max(ans, countLeft + countRight);
				}
				j++;
			}
		}
		return ans;
	}

	//solution 3:��̬�滮��ʱ�䡢�ռ临�Ӷ�O(N)��������ͼ��ʼǣ���Ϊ�������
	int longestValidParentheses3(string s){
		int maxans = 0, n = s.length();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;		//Ҫ�ж�i-2�ǲ���С��0
				}
				//����Ҫ���ж� i - dp[i-1] > 0 �����������0����û�к����ж������ı�Ҫ
				else if (i - dp[i-1] > 0 && s[i - dp[i - 1] - 1] == '(') {			//�ڶ�������ж������Ը��ӣ�Ҫ�������Ӵ����Ѿ���Ч�Ĳ��֣��ҵ������Ӧ��λ�ã��ж��Ƿ�Ϊ������
					//dp[i - dp[i - 1] - 2]���˴�-2��Ϊ���������Ӵ�����ȡǰ����Ч���ų���
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;	
				}
				maxans = max(maxans, dp[i]);
			}
		}
		return maxans;
	}
	//solution 4:����ջ�����������žͽ�������ջ�������žͽ�ջ����ջ���ѵ����ڣ���-1��ջ��Ϊ��һ���߽磻��Ч���ų���ʱ����������ջ����Ϊ�µı߽�
	int longestValidParentheses4(string s) {
		int maxans = 0;
		stack<int> stk;
		stk.push(-1);		//�������������һ��-1����Ϊ��Ч������������������õ��ģ���һ������Ҫ��һ��-1����ǰ��
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				stk.pop();		//��pop���ٿ�ջ������Ϊ��Ч�����ǳɶԳ���
				//ջΪ�գ���ʾ���ִ���������ţ�ǰ��Ľ������������������Ϊ�µı߽�
				if (stk.empty()) {
					stk.push(i);
				}
				else {
					maxans = max(maxans, i - stk.top());
				}
			}
		}
		return maxans;
	}

	//solution 5:���������Ϸ�
	int longestValidParentheses5(string s) {
		int left = 0, right = 0, maxlength = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				left++;
			}
			else {
				right++;
			}
			if (left == right) {
				maxlength = max(maxlength, 2 * right);
			}
			else if (right > left) {
				left = right = 0;
			}
		}
		left = right = 0;
		//��������
		for (int i = (int)s.length() - 1; i >= 0; i--) {
			if (s[i] == '(') {
				left++;
			}
			else {
				right++;
			}
			if (left == right) {
				maxlength = max(maxlength, 2 * left);
			}
			else if (left > right) {
				left = right = 0;
			}
		}
		return maxlength;
	}
};
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	//solution 1:暴力解法，对s中包含的几乎所有字符串进行判断，先从长度为s.length（）字串开始，直至找到或“”为止

	//solution 2:自编代码，时间复杂度O(N^2)
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

	//solution 3:动态规划，时间、空间复杂度O(N)，具体解释见笔记，分为两种情况
	int longestValidParentheses3(string s){
		int maxans = 0, n = s.length();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;		//要判断i-2是不是小于0
				}
				//下面要先判断 i - dp[i-1] > 0 ，如果不大于0，就没有后面判断条件的必要
				else if (i - dp[i-1] > 0 && s[i - dp[i - 1] - 1] == '(') {			//第二种情况判断条件略复杂，要跳过此子串中已经有效的部分，找到与其对应的位置，判断是否为左括号
					//dp[i - dp[i - 1] - 2]，此处-2是为了跳过该子串，获取前面有效括号长度
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;	
				}
				maxans = max(maxans, dp[i]);
			}
		}
		return maxans;
	}
	//solution 4:利用栈，遇到左括号就将索引入栈，右括号就将栈顶出栈；难点在于：将-1入栈作为第一个边界；无效括号出现时，将索引入栈，作为新的边界
	int longestValidParentheses4(string s) {
		int maxans = 0;
		stack<int> stk;
		stk.push(-1);		//必须再最下面放一个-1，因为有效括号数是用索引做差得到的，第一个括号要放一个-1再其前面
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				stk.pop();		//先pop，再看栈顶，因为有效括号是成对出现
				//栈为空，表示出现错误的右括号，前面的结果结束，已其索引作为新的边界
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

	//solution 5:正、逆向结合法
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
		//从右向左
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
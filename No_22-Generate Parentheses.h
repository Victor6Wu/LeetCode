//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> ans;
	vector<char> choice = { '(',')' };
	//solution 1 :递归+回溯，“（”只能出现在第一个和后面几个位置，不可以是最后一个位置
	//ans为返回结果；s为已经构建的string；count为s已经包含的字符数；judgment为左右括号的差
	void generateString(string &s, int countLeft, int countRight, int &n) {	
		if (countLeft == n && countRight == n) {
			ans.push_back(s);
		}
		if (countLeft > n || countRight > n || countLeft < countRight) {	//return的情况就这三种
			return;
		}
		else {
			//(、) 两个括号在添加的时候是平等的，用循环实现
			for (auto& iter : choice) {
				if (iter == '(') countLeft++;
				else  countRight++;
				s.push_back(iter);
				generateString(s, countLeft, countRight, n);
				//回溯
				if (iter == '(') countLeft--;
				else countRight--;
				s.pop_back();
			}
		}
	}

	vector<string> generateParenthesis(int n) {
		string s = "";
		generateString(s, 0, 0, n);
		return ans;
	}
};
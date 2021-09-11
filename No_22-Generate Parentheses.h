//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> ans;
	vector<char> choice = { '(',')' };
	//solution 1 :�ݹ�+���ݣ�������ֻ�ܳ����ڵ�һ���ͺ��漸��λ�ã������������һ��λ��
	//ansΪ���ؽ����sΪ�Ѿ�������string��countΪs�Ѿ��������ַ�����judgmentΪ�������ŵĲ�
	void generateString(string &s, int countLeft, int countRight, int &n) {	
		if (countLeft == n && countRight == n) {
			ans.push_back(s);
		}
		if (countLeft > n || countRight > n || countLeft < countRight) {	//return�������������
			return;
		}
		else {
			//(��) ������������ӵ�ʱ����ƽ�ȵģ���ѭ��ʵ��
			for (auto& iter : choice) {
				if (iter == '(') countLeft++;
				else  countRight++;
				s.push_back(iter);
				generateString(s, countLeft, countRight, n);
				//����
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
//����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ���������Կո�Ϊ�ָ���
//���������ַ���"I am a student. "�������"student. a am I"��
#include<string>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

//��vector�洢
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> strs;
        string str;
        while (getline(ss, str, ' ')) {
            if (!str.empty())           //stringstream��getline
                strs.push_back(str);
        }
        string ans;
        for (int i = strs.size() - 1; i >= 0; i--) {
            ans += strs[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};

//��ջ�洢
class Solution {
public:
    string reverseWords(string s) {
        stack<string>stk;
        for (stringstream ss(s); ss >> s;)stk.push(s);
        for (s = ""; !stk.empty(); stk.pop())s += stk.top() + " ";
        return s.substr(0, s.size() - 1);
    }
};

//˫ָ�뷨���ռ临�Ӷ��Ż����ַ����������

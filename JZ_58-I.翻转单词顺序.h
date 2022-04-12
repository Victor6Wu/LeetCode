//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理，即以空格为分隔符
//例如输入字符串"I am a student. "，则输出"student. a am I"。
#include<string>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

//用vector存储
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> strs;
        string str;
        while (getline(ss, str, ' ')) {
            if (!str.empty())           //stringstream和getline
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

//用栈存储
class Solution {
public:
    string reverseWords(string s) {
        stack<string>stk;
        for (stringstream ss(s); ss >> s;)stk.push(s);
        for (s = ""; !stk.empty(); stk.pop())s += stk.top() + " ";
        return s.substr(0, s.size() - 1);
    }
};

//双指针法，空间复杂度优化，字符串倒叙遍历

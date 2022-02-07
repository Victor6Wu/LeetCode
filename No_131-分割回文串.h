//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//回文串 是正着读和反着读都一样的字符串。
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> tmp;
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        if (j == 0) return true;
        else {
            while (i < j) {
                if (s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        }
    }

    void backtracking(string s, int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(tmp);
            return;
        }
        for (int endIndex = startIndex; endIndex < s.size(); endIndex++) {
            string str(s.begin() + startIndex, s.begin() + endIndex + 1);   //此处要+1，左闭右开的方式初始化
            if (isPalindrome(str)) {        //此处可以优化一下，判断是否回文串用string&，这样对于false的情况就不用取substr了
                tmp.push_back(str);
                backtracking(s, endIndex + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};
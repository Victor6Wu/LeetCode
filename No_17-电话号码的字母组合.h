//给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。字母和数字的映射按照九键键盘。
#include<vector>
#include<string>
using namespace std;

//回溯法，digits中每个元素根据其取值获得一个集合，对集合进行循环，循环内进行递归嵌套
class Solution {
private:
    vector<string> result;
    string combine;
    void backtracking(string& s, int Index) {
        if (Index == s.size()) {
            result.push_back(combine);
            return;
        }
        string tmp;
        switch (s[Index]) {
        case '2':
            tmp = "abc";
            break;
        case '3':
            tmp = "def";
            break;
        case '4':
            tmp = "ghi";
            break;
        case '5':
            tmp = "jkl";
            break;
        case '6':
            tmp = "mno";
            break;
        case '7':
            tmp = "pqrs";
            break;
        case '8':
            tmp = "tuv";
            break;
        case '9':
            tmp = "wxyz";
            break;
        }
        for(int i = 0; i < tmp.size(); i++){
            combine.push_back(tmp[i]);
            backtracking(s, Index + 1);
            combine.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtracking(digits, 0);
        return result;
    }
};
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

//本题用回溯法也可解决，就是容易超时
class Solution1 {
private:
    bool backtracking(const string& s, const unordered_set<string>& wordSet, int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtracking(s, wordSet, 0);
    }
};

//完全背包问题
class Solution2 {
public:
    //比较字符串s从index往前的字符与字符串str能否匹配
    bool compareStr(string& s, string& str, int index) { //index表示s剩余的可比较字符数
        int n = str.size() - 1;
        while (n >= 0 && index > 0) {
            if (s[index - 1] != str[n]) return false;
            else {
                index--;
                n--;
            }
        }
        if (index <= 0 && n >= 0) return false;
        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);       //dp[j]表示字符串s在位置j之前的字符匹配情况
        dp[0] = true;           //0之前就是没有字符，肯定是true
        //i循环物品，j循环背包
        for (int j = 0; j < s.size() + 1; j++) {
            for (int i = 0; i < wordDict.size(); i++) {
                if (j >= wordDict[i].size()) {
                    dp[j] = dp[j] || (dp[j - wordDict[i].size()] && compareStr(s, wordDict[i], j));
                }
            }
        }
        return dp[s.size()];
    }
};
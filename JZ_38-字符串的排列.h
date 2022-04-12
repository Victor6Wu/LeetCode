//输入一个字符串，打印出该字符串中字符的所有排列。
//你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

//回溯法，用unordered_set实现去重
class Solution1 {
private:
    unordered_set<string> ans;
    string tmp;
public:
    void backtrace(string& s, vector<bool>& sign) {
        if (tmp.size() == s.size()) {
            ans.insert(tmp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (sign[i]) continue;
            else {
                tmp.push_back(s[i]);
                sign[i] = true;
                backtrace(s, sign);
                sign[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        vector<bool> sign(s.size(), false);
        backtrace(s, sign);
        return vector<string>(ans.begin(), ans.end());
    }
};

//在递归函数中实现去重，字符串需要先进行排序
class Solution2 {
private:
    vector<string> ans;
    string tmp;
public:
    void backtrace(string& s, vector<bool>& sign) {
        if (tmp.size() == s.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            //树层去重，非常关键的一点是：sign[i - 1] == false，否则会影响树枝
            if (i > 0 && s[i] == s[i - 1] && sign[i - 1] == false) continue; 
            if (sign[i]) continue;
            else {
                tmp.push_back(s[i]);
                sign[i] = true;
                backtrace(s, sign);
                sign[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());       //因为后面去重需要用到前后字符重复的方法，因此需要对字符串排序
        vector<bool> sign(s.size(), false);
        backtrace(s, sign);
        return ans;
    }
};

//可以借用字典序的方法，排序后逐个将下一个字典序存入，本身也避免了重复
class Solution {
public:
    bool nextPermutation(string& s) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
        sort(s.begin(), s.end());
        do {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};
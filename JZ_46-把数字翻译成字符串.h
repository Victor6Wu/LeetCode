//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
//一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
#include<vector>
#include<string>
using namespace std;

//动态规划法，近似于斐波那契数列，只是有一定的要求条件
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        if (str.size() <= 1) return str.size();
        vector<int> dp(str.size() + 1);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= str.size(); i++) {
            int index = stoi(str.substr(i - 2, 2));
            if (index >= 10 && index <= 25) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[str.size()];
    }
};
//空间优化
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        if (str.size() <= 1) return str.size();
        int first = 1, second = 1;
        int cur;
        for (int i = 2; i <= str.size(); i++) {
            int index = stoi(str.substr(i - 2, 2));
            if (index >= 10 && index <= 25) {
                cur = first + second;
                first = second;
                second = cur;
            }
            else {
                cur = second;
                first = second;
                second = cur;
            }
        }
        return second;
    }
};
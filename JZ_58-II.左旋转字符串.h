//输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
#include<string>
using namespace std;

//方法1：将字符串分成两段
class Solution1 {
public:
    string reverseLeftWords(string s, int n) {
        string s1 = s.substr(0, n);
        string s2 = s.substr(n, s.size() - n);
        return s2 + s1;
    }
};

//方法2：多次调用reverse
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
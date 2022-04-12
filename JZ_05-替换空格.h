//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
#include<string>
using namespace std;

//方法1：借用新的数组
class Solution1 {
public:
    string replaceSpace(string s) {
        string ans;
        for (char it : s) {
            if (it != ' ') {
                ans.push_back(it);
            }
            else {
                ans += "%20";
            }
        }
        return ans;
    }
};

//方法2：扩充数组，从后向前填充
class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size() - 1;
        //统计空格数
        int count = 0;
        for (char it : s) {
            if (it == ' ') {
                count++;
            }
        }

        //扩充字符串
        s.resize(s.size() + count * 2);
        int newSize = s.size() - 1;
        //逆序填充
        while (oldSize != newSize) {
            if (s[oldSize] != ' ') {
                s[newSize] = s[oldSize];
            }
            else {
                s[newSize] = '0';
                s[newSize - 1] = '2';
                s[newSize - 2] = '%';
                newSize -= 2;
            }
            oldSize--;
            newSize--;
        }
        return s;
    }
};
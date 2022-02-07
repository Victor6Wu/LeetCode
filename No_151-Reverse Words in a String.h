//给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
//请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
#include<string>
using namespace std;

class Solution {
public:
    //删除冗余的空格
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0;
        //删除头部空格（所谓的删除就是将快指针向后挪动）
        while (fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }

        //删除中间冗余的空格
        for (; fastIndex < s.size(); fastIndex++) {
            //只有空格连续出现时才跳过（删除）
            if (fastIndex > 1 && s[fastIndex] == ' ' && s[fastIndex - 1] == s[fastIndex]) {
                continue;
            }
            //否则，需要将快指针处的字符覆盖到慢指针处
            else {
                s[slowIndex++] = s[fastIndex];
            }
        }

        //删除字符末尾的空格。收尾情况有三种：普通字符，一个空格，多个空格
        //根据上一步的循环，slowIndex - 1的位置会可能为' '
        if (slowIndex > 1 && s[slowIndex - 1] == ' ') {
            s.resize(slowIndex - 1);
        }
        else {
            s.resize(slowIndex);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);                   //删除冗余空格
        reverse(s.begin(), s.end());            //反转整个字符串
        for (int i = 0; i < s.size(); i++) {    //挨个单词翻转。因为已经取出头尾的空格，所以第一个单词默认从0开始
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);      //这里注意，库函数reverse采用的是左闭右开
            i = j;
        }
        return s;
    }
};
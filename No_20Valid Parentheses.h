#pragma once
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
//determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
#include<string>
#include<Stack>
using namespace std;

class Solution {
public:
    //solution 1: 利用栈迭代实现，《数据结构》P93页，特别注意Stack库中的top和pop要分开，与书上描述的不同
    bool isValid(string s) {
        stack<char>  Sta;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            switch (s[i])
            {
                case '(': case '[': case '{': Sta.push(s[i]); break;
                case ')': if ((Sta.empty()) || ('(' != Sta.top())) return false; Sta.pop(); break;
                case ']': if ((Sta.empty()) || ('[' != Sta.top())) return false; Sta.pop(); break;
                case '}': if ((Sta.empty()) || ('}' != Sta.top())) return false; Sta.pop(); break;
                default: break;
            }
        }
        return Sta.empty();
    }
};
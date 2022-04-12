//给定的字符串有*和其他字符组成，要求将*放在前面，其他的按照原有顺序放在后面
//时间复杂度O(N)，空间复杂度O(1)
#include<iostream>
#include<string>
using namespace std;

//从后向前遍历，将遇到*时就往前找其他字符，交换二者，空间复杂度O(1)
void solution1() {
    string s;
    while (cin >> s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '*') continue;
            bool sign = true;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] != '*') {
                    swap(s[i], s[j]);
                    sign = false;
                    break;
                }
            }
            if (sign) break;
        }
        cout << s << endl;
    }
    return;
}

//时间复杂度O(N)，个人感觉空间复杂度不是O(1)
void solution2() {
    string s, s1, s2;
    cin >> s;
    for (auto& c : s) {
        if (c == '*')
            s1 += c;
        else
            s2 += c;
    }
    cout << s1 + s2 << endl;
    return;
}

//最接近题目要求的写法，两次遍历，第一次填其他字符，第二次填*
void solution3() {
    string str;
    cin >> str;
    int j = str.size() - 1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] != '*') {
            str[j--] = str[i];
        }
    }
    while (j >= 0)
        str[j--] = '*';
    cout << str << endl;
}
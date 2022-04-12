//�������ַ�����*�������ַ���ɣ�Ҫ��*����ǰ�棬�����İ���ԭ��˳����ں���
//ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)
#include<iostream>
#include<string>
using namespace std;

//�Ӻ���ǰ������������*ʱ����ǰ�������ַ����������ߣ��ռ临�Ӷ�O(1)
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

//ʱ�临�Ӷ�O(N)�����˸о��ռ临�ӶȲ���O(1)
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

//��ӽ���ĿҪ���д�������α�������һ���������ַ����ڶ�����*
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
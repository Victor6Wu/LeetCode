#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printOut() {
    string s = "", tmp = "";
    char c;
    vector<string> v;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') {
                v.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += s[i];
        }
        v.push_back(tmp);
        tmp = "";           //注意不要忘了清空tmp
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            i != v.size() - 1 && cout << ",";
        }
        v.clear();
        cout << endl;
    }
    return;
}
//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
#include<string>
#include<vector>    
using namespace std;

class Solution1 {
public:
    vector<int> printNumbers(int n) {
        string s;
        while (n-- > 0) {
            s.push_back('9');
        }
        vector<int> ans;
        for (int i = 1; i <= stoll(s); i++) {
            ans.push_back(i);
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> printNumbers(int n) {
        long long max = 1;
        while (n-- > 0) {
            max *= 10;
        }
        vector<int> ans;
        for (int i = 1; i < max; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};
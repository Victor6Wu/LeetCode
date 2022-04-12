//在一个长为n的字符串中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
#include<unordered_map>
#include<string>
using namespace std;

//借用哈希表，先将字符出现的次数统计下来，再去遍历字符串，可以用数组代替map
class Solution1 {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> table;         //vector<int> table(128, 0);
        for (const char c : str) {
            table[c]++;
        }
        for (int i = 0; i < str.size(); i++) {
            if (table[str[i]] == 1) return i;
        }
        return -1;
    }
};

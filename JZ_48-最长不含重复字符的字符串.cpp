//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//贪心法，滑动窗，字符不一定只有小写字母，所以初始化长度为128的数组
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int index = 0;
        int maxLen = 0;
        int tmp_len = 0;
        vector<int> vec(128, -1);
        vector<int> loc = vec;
        while (index < n) {
            if (loc[s[index]] == -1) {
                loc[s[index]] = index;
                tmp_len++;
                maxLen = max(maxLen, tmp_len);
                index++;
            }
            else {
                int tmp = loc[s[index]] + 1;
                loc = vec;
                tmp_len = 0;
                index = tmp;
            }
        }
        return maxLen;
    }
};

//代码优化，用左右边界表示滑动窗，而不是每次更新左边界后从新开始拓展右边界
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int left = 0, right = 0;
        int maxLen = 0;
        vector<int> loc(128, -1);
        for (; right < n; right++) {
            //重复的字符在当前的窗内
            if (loc[s[right]] >= left) {        
                left = loc[s[right]] + 1;   //更新左边界
            }

            loc[s[right]] = right;          //更新重复字符的最新位置
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
//给你一个字符串 s 和一个整数 repeatLimit ，用 s 中的字符构造一个新字符串 repeatLimitedString ，使任何字母 连续 出现的次数都不超过 repeatLimit 次。你不必使用 s 中的全部字符。
//返回 字典序最大的 repeatLimitedString 。
#include<String>
#include<unordered_map>
using namespace std;

//先将字符串s提供的所有字符按照从z到a的顺序拼接成一个新的字符串；
//排查连续重复的字符，数量超过给定限制时，就和后面第一个不重复的字符进行交换；
//主要考虑找不到不重复字符的时候，要将后面的全部删除
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        //统计每个字符出现的次数
        vector<int> freq(26);
        for (char ch : s) {
            ++freq[ch - 'a'];
        }
        //构建新字符串
        string ans;
        for (int i = 25; i >= 0; i--) {
            for (int j = 1; j <= freq[i]; j++) {
                ans.push_back('a' + i);
            }
        }

        int cnt = 1;    //记录字符重复次数
        // 双指针调整新字符串
        for (int left = 1, right = 2; left < ans.size(); ++left) {
            if (ans[left - 1] != ans[left]) {
                cnt = 1;
            }
            else {
                ++cnt;
                if (cnt > repeatLimit) {
                    //这里更新right是有技巧的，max(left + 1，right)的好处在于，假如上一次为了找到不重复的字符，right已经向后移动了很远
                    //下一次更新的时候就在上次基础上跟新，而不用重新查找
                    right = max(right, left + 1);       
                                                        
                    while (right < ans.size() && ans[left] == ans[right]) {
                        ++right;
                    }
                    if (right < s.size()) {
                        swap(ans[left], ans[right]);
                        cnt = 1;
                    }
                    else {
                        ans.erase(ans.begin() + left, ans.end());
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
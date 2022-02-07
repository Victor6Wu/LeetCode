//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
//返回一个表示每个字符串片段的长度的列表。
#include<vector>
#include<string>
using namespace std;

//自编代码
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int startIndex = 0;
        int endIndex = 0;
        vector<int> result;
        //统计所有字符最后一次出现的索引/位置
        vector<int> charIndexs(26, 0);
        for (int i = 0; i < s.size(); i++) {
            int tmp = charIndexs[s[i] - 'a'];
            if (i > tmp) {
                charIndexs[s[i] - 'a'] = i;
            }
        }
        //开始划分字符串，内循环采用左闭右闭区间，在过程中更新endIndex
        while (startIndex < s.size()) {
            for (int i = startIndex; i <= endIndex; i++) {
                endIndex = max(endIndex, charIndexs[s[i] - 'a']);
            }
            result.push_back(endIndex - startIndex + 1);
            endIndex++;
            startIndex = endIndex;
        }
        return result;
    }
};

//代码改进
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = { 0 }; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
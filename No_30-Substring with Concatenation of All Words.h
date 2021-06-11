//You are given a string s and an array of strings words of the same length. 
//Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, 
//and without any intervening characters.
//You can return the answer in any order.

#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string_view>
using namespace std;

class Solution {
public:
	//solution 1: 自写代码，时间复杂度O(n^2)，空间复杂度2*O(n);
	vector<int> findSubstring1(string s, vector<string>& words) {
		unordered_multiset<string> wordsA(words.begin(), words.end()), wordsB;
		vector<int> ans;
		int word_len = words[0].size();
		int s_len = s.size();
		int ptr = 0;
		while (ptr < s_len-word_len + 1) {
			string str = s.substr(ptr, word_len);
			auto it = wordsA.find(str);
			if (it != wordsA.end()) {
				wordsB.insert(*it);			//存储已经确定找到的word
				wordsA.erase(it);			//这里必须是迭代器，不能加*，否则会把重复的全都删除
				//如果匹配的已经时最后一个，则存储，关键是要跟新指针位置，从最初的位置前进一步
				if (wordsA.empty()) {
					ans.push_back(ptr - (words.size() - 1) * word_len);
					ptr = ptr - (words.size() - 1) * word_len + 1;
					unordered_multiset<string> temp = wordsA;
					wordsA = wordsB;
					wordsB = temp;
					continue;
				}
				ptr += word_len;
			}
			else {
				//出错的时候要判断之前是否有匹配成功的，有就要删除并更新指针位置
				if (!wordsB.empty()) {
					wordsA.insert(wordsB.begin(), wordsB.end());
					ptr = ptr - wordsB.size() * word_len + 1;
					wordsB.clear();
					continue;
				}
				++ptr;
			}
		}
		return ans;
	}

	//solution 2: 滑动窗法
    //不满足的条件有两种：1.没在words中找到匹配单词； 2.尽管找到匹配单词，但是之前已经出现，且数目超出给定的个数
    //已经完全匹配，但是后面可能还会有完全匹配的，采用上述不满足条件的两种情况即可解决此问题
    vector<int> findSubstring2(string s, vector<string>& words) {
        if (s.empty() || words.empty()) {
            return {};
        }

        std::unordered_map<string/*word*/, int/*count*/> wordsTable;
        for (const std::string& word : words) {
            ++wordsTable[word.c_str()];
        }

        std::size_t lenWord = words[0].size();
        std::size_t numWords = words.size();
        std::size_t lenAllWords = lenWord * numWords;

        std::vector<int> result;
        //字符串并不一定是由一个单词一个单词构成的，中间会出现随机的字符，所以要重复查找 word_len 次，即从索引0、1...开始；
        // 0 k 2k 3k ...; 1 k+1 2k+1 3k+1 ...; 2 k+2 2k+2 3k+2 ...; ... 
        for (std::size_t i = 0; i < lenWord; ++i) {
            std::size_t left = i;
            std::size_t right = i;

            std::unordered_map<std::string/*word*/, int/*count*/> sTable;

            std::size_t count = 0;
            while (right + lenWord <= s.size()) {
                // right -> 
                std::string str{ s.c_str() + right, lenWord };
                right += lenWord;

                if (wordsTable.count(str) == 0) {
                    count = 0;
                    left = right;           //当有左边界向右移动一个单词长度
                    sTable.clear();
                }
                else {
                    ++count;                //计数码+1
                    ++sTable[str];          //当匹配成功后添加到sTable

                    //当出现重复单词时，根据words中的数目对窗口进行更新，左边界不断移动，直到满足数目条件
                    while (sTable[str] > wordsTable[str]) {     //sTable中的某个单词数超过给定的words中的数目
                        // left ->
                        std::string leftStr{ s.c_str() + left, lenWord };   //从窗口左边界开始剔除sTable单词
                        left += lenWord;            //剔除后开始更新左边界
                        --sTable[leftStr];
                        --count;                    //计数码-1
                    }
                }
                //判断是否已经找到恰好满足words中单词串联的字符串
                if (count == numWords) {
                    result.emplace_back(left);
                }
            }
        }

        return result;
    }
};

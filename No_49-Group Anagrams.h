//Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
//typically using all the original letters exactly once.

#include<string>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: 自编代码，利用散列表，键是multiset，值为存放单词的数组
	vector<vector<string>> groupAnagrams1(vector<string>& strs) {
		unordered_map<multiset<char>,vector<string>> search_table;
		int size_strs = strs.size();
		for (int i = 0; i < size_strs; ++i) {
			string word = strs[i];
			multiset<char> temp(word.begin(), word.end());			//将string类型的单词转成存放字母的set
			//下面的语句可以简化，不需要先查找在判断，参考solution 2 
			auto it = search_table.find(temp);
			if (it != search_table.end()) {
				it->second.push_back(word);
			}
			else {
				search_table[temp] = {word};					//没出现过即增添新的键值对
			}
		}
		vector<vector<string>> ans;
		auto map_it = search_table.cbegin();
		while (map_it != search_table.cend()) {
			ans.push_back(map_it->second);
			++map_it;
		}
		return ans;
	}

	//solution 2 ：以重新排序后的string作为键
	vector<vector<string>> groupAnagrams2(vector<string>& strs) {
		unordered_map<string, vector<string>> m;			//构建散列表
		for (string& str : strs) {
			string temp = str;
			sort(temp.begin(), temp.end());					//思路与solution 1 类似，区别在于将排序后的字符串作为键

			m[temp].push_back(str);							//根本不需要solution 1 中那种条件语句，有就添加，没有就新建
		}

		vector<vector<string>> res;
		for (auto& it : m) {
			res.push_back(it.second);
		}

		return res;
	}
};
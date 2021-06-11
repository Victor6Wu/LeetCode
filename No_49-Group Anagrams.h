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
	//solution 1: �Ա���룬����ɢ�б�����multiset��ֵΪ��ŵ��ʵ�����
	vector<vector<string>> groupAnagrams1(vector<string>& strs) {
		unordered_map<multiset<char>,vector<string>> search_table;
		int size_strs = strs.size();
		for (int i = 0; i < size_strs; ++i) {
			string word = strs[i];
			multiset<char> temp(word.begin(), word.end());			//��string���͵ĵ���ת�ɴ����ĸ��set
			//����������Լ򻯣�����Ҫ�Ȳ������жϣ��ο�solution 2 
			auto it = search_table.find(temp);
			if (it != search_table.end()) {
				it->second.push_back(word);
			}
			else {
				search_table[temp] = {word};					//û���ֹ��������µļ�ֵ��
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

	//solution 2 ��������������string��Ϊ��
	vector<vector<string>> groupAnagrams2(vector<string>& strs) {
		unordered_map<string, vector<string>> m;			//����ɢ�б�
		for (string& str : strs) {
			string temp = str;
			sort(temp.begin(), temp.end());					//˼·��solution 1 ���ƣ��������ڽ��������ַ�����Ϊ��

			m[temp].push_back(str);							//��������Ҫsolution 1 ������������䣬�о���ӣ�û�о��½�
		}

		vector<vector<string>> res;
		for (auto& it : m) {
			res.push_back(it.second);
		}

		return res;
	}
};
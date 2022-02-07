//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#include<unordered_map>
#include<string>
using namespace std;

//���ù�ϣ��
class Solution1 {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> map;
		for (char& it : s) {
			map[it]++;
		}
		for (char& it : t) {
			map[it]--;
		}
		for (auto& it : map) {
			if (it.second != 0) {
				return false;
			}
		}
		return true;
	}
};

//ֻ�漰���ַ�������ASCII�����鼴��
class Solution2 {
public:
	bool isAnagram(string s, string t) {
		int record[58] = { 0 };
		for (const char& it : s) {
			record[it - 'A']++;
		}

		for (const char& it : t) {
			record[it - 'A']--;
		}

		for (auto& it : record) {
			if (it != 0) return false;
		}
		return true;
	}
};
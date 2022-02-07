//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
#include<string>
#include<vector>
using namespace std;

//修改No_242题，将判断条件改成<0
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.size() > magazine.size()) {
			return false;
		}

		int record[58] = { 0 };
		for (const char& it : magazine) {
			record[it - 'A']++;
		}

		for (const char& it : ransomNote) {
			record[it - 'A']--;
		}

		for (auto& it : record) {
			if (it < 0) return false;
		}
		return true;
	}
};
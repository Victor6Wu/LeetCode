//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
#include<string>
#include<vector>
using namespace std;

//方法1：挨个位置判断
class Solution1 {
public:
	//判断两个字符串是否异位词
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
    vector<int> findAnagrams(string s, string p) {
        if (size(s) == 0 || size(p) == 0 || size(s) < size(p)) {
            return {};
        }
        vector<int> ans;
		int n = size(p);
		for (int i = 0; i <= size(s) - size(p); i++) {
			string tmp = s.substr(i, n);
			if (isAnagram(tmp, p)) {
				ans.push_back(i);
			}
		}
		return ans;
    }
};

//方法2：滑动窗的方法进行比对，这样两个窗直接的字符不需要重复计入哈希表
class Solution2 {
public:
	vector<int> findAnagrams(string s, string p) {
		int sLen = s.size();
		int pLen = p.size();
		if (sLen < pLen) return {};

		vector<int> ans;
		vector<int> sCount(26);
		vector<int> pCount(26);
		//初始化s的第一个窗以及P对应的哈希表
		for (int i = 0; i < pLen; i++) {
			pCount[p[i] - 'a']++;			//记录滑动窗中的字符数
			sCount[s[i] - 'a']++;			//记录字符串的字符出现次数
		}
		//判断第一个位置
		if (pCount == sCount) ans.push_back(0);

		//滑动窗开始向后移动，将窗中第一个字符对应的数值-1，窗尾即将包括的字符+1
		for (int i = 0; i < sLen - pLen; i++) {
			sCount[s[i] - 'a']--;
			sCount[s[i + pLen] - 'a']++;

			if (pCount == sCount) ans.push_back(i + 1);
		}
		return ans;
	}
};

//方法3：优化的滑动窗，增添一个差异值，免去比较vector的步骤
class Solution3 {
public:
	vector<int> findAnagrams(string s, string p) {
		int sLen = s.size();
		int pLen = p.size();
		if (sLen < pLen) return {};

		vector<int> ans;
		vector<int> count(26);				//记录26个字母的出现次数的差值
		for (int i = 0; i < pLen; i++) {
			count[s[i] - 'a']++;			//滑动窗中的字符出现的次数，增加
			count[p[i] - 'a']--;			//p中字符出现即将滑动窗中的-1
		}

		int differ = 0;		//差异值，用于表示出现次数不对应的字符个数
		for (int i = 0; i < 26; i++) {
			if (count[i] != 0) {
				differ++;
			}
		}
		if (differ == 0) {
			ans.push_back(0);		//记下第一个滑动窗
		}
			
		//移动滑动窗，根据count中的情况对differ进行维护，然后直接根据更新后的differ即可判断当前的滑动窗是否是字母异位词
		for (int i = 0; i < sLen - pLen; i++) {
			//判断窗首字符出现次数差值，特别注意：这个字符从窗中去除，并且会对字母出现次数产生“相同”和“不同”这两种情况的转变时，才有必要考虑differ
			if (count[s[i] - 'a'] == 1) {		//字母次数从不同转成相同
				differ--;
			}
			else if (count[s[i] - 'a'] == 0) {	//字母次数从相同转成不同
				differ++;
			}
			count[s[i] - 'a']--;				//字母次数-1

			if (count[s[i + pLen] - 'a'] == -1) {		//字母次数从不同转成相同
				differ--;
			}
			else if (count[s[i + pLen] - 'a'] == 0) {	//字母次数从相同转成不同
				differ++;
			}
			count[s[i + pLen] - 'a']++;				//字母次数-1

			if (differ == 0) {
				ans.push_back(i + 1);
			}
		}
		return ans;
	}
};

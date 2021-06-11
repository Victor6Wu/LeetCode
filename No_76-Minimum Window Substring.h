//Given two strings s and t of lengths m and n respectively, 
//return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
//If there is no such substring, return the empty string "".
//The testcases will be generated such that the answer is unique.
//A substring is a contiguous sequence of characters within the string.
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:自编代码，有些情况无法满足，解答错误
	//string minWindow(string s, string t) {
	//	//构建一个数组用于存放t中出现的字母个数
	//	int map_t[128];
	//	for (int i = 0; i < 128; i++) {
	//		map_t[i] = -1;
	//	}

	//	for (int i = 0; i < t.size(); ++i) {
	//		char c = t[i];
	//		map_t[(int)c] = 0;
	//	}

	//	for (int i = 0; i < t.size(); ++i) {
	//		char c = t[i];
	//		map_t[(int)c]++;
	//	}

	//	//先找到滑动窗的第一个左边界
	//	int left_ptr = 0, len_s = s.size();
	//	for (; left_ptr < len_s; ++left_ptr) {
	//		if (map_t[s[left_ptr]] != false) break;
	//	}
	//	int right_ptr = left_ptr;

	//	//构建map存储已经找到的字符,key表示索引，value表示字符
	//	string str = s;
	//	bool signal = false;
	//	map<int, char> map_s;
	//	for (; right_ptr < len_s; ++right_ptr) {
	//		if (map_t[s[right_ptr]] != -1) {
	//			if (map_t[s[right_ptr]] > 0) {
	//				--map_t[s[right_ptr]];
	//				map_s[right_ptr] = s[right_ptr];
	//				continue;
	//			}
	//			//考虑需要更新左边界的情况
	//			if (map_t[s[right_ptr]] == 0) {
	//				//如果此时刚好匹配，需要取出此时窗口表示的子串
	//				if (map_s.size() == t.size()) {
	//					auto left_it = map_s.begin();
	//					auto right_it = map_s.end();
	//					right_it--;
	//					int len_str = right_it->first - left_it->first + 1;    //需要+1，因为滑动窗包含边界的元素
	//					if (len_str <= str.size()) {
	//						str = s.substr(left_it->first, len_str);
	//						signal = true;
	//					}
	//					//更新左边界
	//					auto it = map_s.begin();
	//					map_s.erase(it);
	//					left_ptr = map_s.begin()->first;
	//				}
	//				//需要考虑s中有连续字符的情况，如s="aaaabbbcdd"，t="abcdd"
	//				if ( map_s.size() >= 2 && (s[right_ptr] == s[right_ptr - 1])) {
	//					map_s.erase(right_ptr - 1);
	//					map_s[right_ptr] = s[right_ptr];
	//					continue;
	//				}

	//				//更新左边界附带的一系列操作：释放map_s中新的左边界左侧的元素，同步增加map_t中的个数
	//				auto it = map_s.begin();
	//				while (it != map_s.end()) {
	//					//循环查找
	//					if (it->second != s[right_ptr]) {
	//						map_t[it->second]++;		//增加map_t中对应字符的个数
	//						map_s.erase(it);			//释放map_s中新边界左侧的元素
	//						it = map_s.begin();
	//					}
	//					//找到对应元素后，只需要更新左边界，同时修改该元素在map_s中的键
	//					if (it->second == s[right_ptr]) {
	//						map_s.erase(it);
	//						map_s[right_ptr] = s[right_ptr];		//修改该元素在map_s中的键
	//						//下面这种表示方法非常好，避免了考虑map_s中是否仅有一个元素的情况
	//						left_ptr = map_s.begin()->first;		//更新滑动窗的左边界
	//						break;
	//					}
	//				}
	//					
	//			}
	//		}
	//	}

	//	//循环结束后需要检查map_s，防止遗漏s尾部附近满足题目条件的子串
	//	if (map_s.size() == t.size()) {
	//		auto left_it = map_s.begin();
	//		auto right_it = map_s.end();
	//		right_it--;
	//		int len_str = right_it->first - left_it->first + 1;    //需要+1，因为滑动窗包含边界的元素
	//		if (len_str <= str.size()) {
	//			str = s.substr(left_it->first, len_str);
	//			signal = true;
	//		}
	//	}
	//	if(signal) return str;
	//	return "";
	//}

	
	/*
	* //solution 1:滑动窗法,采用map
	unordered_map<char, int> map_t, map_s;
	//构建检查覆盖与否的函数
	bool check() {
		for (const auto& p : map_t) {
			if (map_s[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c : t) {
			++map_t[c];
		}

		int left = 0, right = -1;
		int len = INT_MAX, temp_left = -1;		//temp_left除了可以存储子串的起点，也相当于一个signal，表明是否出现满足题目条件的字串

		while (right < int(s.size())) {			//此处s.size()要转成int类型，其本身是无符号整数，和-1无法比较
			if (map_t.find(s[++right]) != map_t.end()) {
				++map_s[s[right]];
			}
			while (check() && left <= right) {
				//右移滑动窗的左边界之前，保存此时的子串
				if (right - left + 1 < len) {
					len = right - left + 1;		//存储此时滑动窗的窗长
					temp_left = left;			//存储此时滑动窗的左边界
				}
				//右移滑动窗的左边界
				if (map_t.find(s[left]) != map_t.end()) {//判断此时左边界的字符在t中与否
					--map_s[s[left]];	//减1后最少等于0，因为左边界右移将要扫过的位置都是右边界已经扫过的位置
				}
				++left;
			}
		}
		//返回满足条件的子串
		return temp_left == -1 ? "" : s.substr(temp_left, len);
	}*/

	//solution 2:滑动窗法,采用数组代替map
	int map_t[128], map_s[128];
	//构建检查覆盖与否的函数
	bool check() {
		for (int i = 0; i < 128;++i) {
			if (map_s[i] < map_t[i]) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c : t) {
			++map_t[c];
		}

		int left = 0, right = -1;
		int len = INT_MAX, temp_left = -1;		//temp_left除了可以存储子串的起点，也相当于一个signal，表明是否出现满足题目条件的字串

		while (right < int(s.size())) {			//此处s.size()要转成int类型，其本身是无符号整数，和-1无法比较
			if (map_t[s[++right]] != 0) {
				++map_s[s[right]];
			}
			while (check() && left <= right) {
				//右移滑动窗的左边界之前，保存此时的子串
				if (right - left + 1 < len) {
					len = right - left + 1;		//存储此时滑动窗的窗长
					temp_left = left;			//存储此时滑动窗的左边界
				}
				//右移滑动窗的左边界
				if (map_t[s[left]] != 0) {//判断此时左边界的字符在t中与否
					--map_s[s[left]];	//减1后最少等于0，因为左边界右移将要扫过的位置都是右边界已经扫过的位置
				}
				++left;
			}
		}
		//返回满足条件的子串
		return temp_left == -1 ? "" : s.substr(temp_left, len);
	}
};

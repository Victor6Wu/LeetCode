//给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，请你判断二者是否相等。# 代表退格字符。
//如果相等，返回 true ；否则，返回 false 。
//注意：如果对空文本输入退格字符，文本继续为空。
#include<string>
using namespace std;

//solution1:重构字符串法，遍历两个字符串，分别进行重构然后再比较
class Solution1 {
public:
	bool backspaceCompare(string s, string t) {
		string comS, comT;
		for (char it : s) {
			if (it != '#') {
				comS.push_back(it);
				continue;
			}
			if (it == '#' && comS.empty()) {
				continue;
			}
			comS.pop_back();
		}

		for (char it : t) {
			if (it != '#') {
				comT.push_back(it);
				continue;
			}
			if (it == '#' && comT.empty()) {
				continue;
			}
			comT.pop_back();
		}

		return (comS == comT);
	}
};

//solution2:双指针法，逆序遍历字符串
class Solution2 {
public:
	bool backspaceCompare(string s, string t) {
		int i = s.size() - 1;
		int j = t.size() - 1;
		int skipS = 0, skipT = 0;
		while (i >= 0 || j >= 0) {			//这里必须是或的关系，因为两个字符串有可能不是同时遍历结束
			while (j >= 0 && (skipT != 0 || t[j] == '#')) {
				if (t[j] == '#') {
					skipT++;
					j--;
				}
				else {
					skipT--;
					j--;
				}
			}
			while (i >= 0 && (skipS != 0 || s[i] == '#')) {
				if (s[i] == '#') {
					skipS++;
					i--;
				}
				else {
					skipS--;
					i--;
				}
			}

			if (i >= 0 && j >= 0) {
				if (s[i] != t[j]) {
					return false;
				}
				i--;
				j--;
				continue;		//此处必须要有continue，避免一个字符串遍历完毕，另一个还没结束的情况
			}

			if (i != j) return false;		//这里必须对i和j进行比较，否则当i=-1,j>=0时，可能会无限循环
		}
		return true;
	}
};
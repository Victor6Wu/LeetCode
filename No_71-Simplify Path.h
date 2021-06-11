#pragma once
//Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, 
//convert it to the simplified canonical path.
#include<string>
#include<stack>
#include <fstream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	//solution 1: 利用栈实现回溯，自写代码，很多地方都有待改进
	string simplifyPath1(string path) {
		path = path + "/";					//必须要先在最后增加一个‘/’，因为每次判断是以遇到‘/’为标志，而实际输入的path最后可能没有‘/’
		stack<string> st;
		int len = path.length();
		string word, ans;					//创建空的word作为每次push和pop的基本单位，ans用于表示最终结果
		for (int i = 0; i < len; ++i) {
			if (path[i] == '/') {			//以‘/’作为一个判断符号
				if (word.empty()) continue;	//遇到word为空，表明上一个仍是‘/’，特别注意不能将空的word压入栈中
				if (word == "..") {				//当word为".."时，要考虑返回上一级目录，但是如果已经在根目录了，就不能pop
					if (!st.empty())
						st.pop();
				}
				else if(word != ".") st.push(word);		//最后要判断的是"."，只要此时不为"."，均可入栈
				word = "";					//要将入栈的基本单元重置为空
				continue;
			}
			else
			{
				word.push_back(path[i]);	//没遇到判断符"/"时，继续累加word
			}
		}

		int st_len = st.size();
		string temp;
		//输出最终结果
		if (st.empty()) return "/";			//如果在根目录，就直接返回"/"
		while (!st.empty()) {
			temp = "/" + st.top();			//结果中每个具体的目录前要增加一个"/"
			ans = temp + ans;				//因为栈是 后进先出 ，所以pop出来的要放在后面
			st.pop();
		}
		return ans;
	}

	//solution 2: 借鉴他人的代码
	string simplifyPath(string path) {
		stringstream is(path);
		vector<string> strs;
		string ans = "", tmp = "";
		//以"/"为分隔符，对其中内容进行判断
		while (getline(is, tmp, '/')) {
			if (tmp == "" || tmp == ".")
				continue;
			else if (tmp == ".." && !strs.empty())		//特别注意要在strs不为空的情况下，否则会报错
				strs.pop_back();
			else if (tmp != "..")
				strs.push_back(tmp);
		}
		for (string str : strs)
			ans += "/" + str;				//因为不是栈，就从前往后加即可
		if (ans.empty())
			return "/";
		return ans;
	}
};
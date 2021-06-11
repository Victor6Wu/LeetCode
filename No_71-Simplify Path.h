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
	//solution 1: ����ջʵ�ֻ��ݣ���д���룬�ܶ�ط����д��Ľ�
	string simplifyPath1(string path) {
		path = path + "/";					//����Ҫ�����������һ����/������Ϊÿ���ж�����������/��Ϊ��־����ʵ�������path������û�С�/��
		stack<string> st;
		int len = path.length();
		string word, ans;					//�����յ�word��Ϊÿ��push��pop�Ļ�����λ��ans���ڱ�ʾ���ս��
		for (int i = 0; i < len; ++i) {
			if (path[i] == '/') {			//�ԡ�/����Ϊһ���жϷ���
				if (word.empty()) continue;	//����wordΪ�գ�������һ�����ǡ�/�����ر�ע�ⲻ�ܽ��յ�wordѹ��ջ��
				if (word == "..") {				//��wordΪ".."ʱ��Ҫ���Ƿ�����һ��Ŀ¼����������Ѿ��ڸ�Ŀ¼�ˣ��Ͳ���pop
					if (!st.empty())
						st.pop();
				}
				else if(word != ".") st.push(word);		//���Ҫ�жϵ���"."��ֻҪ��ʱ��Ϊ"."��������ջ
				word = "";					//Ҫ����ջ�Ļ�����Ԫ����Ϊ��
				continue;
			}
			else
			{
				word.push_back(path[i]);	//û�����жϷ�"/"ʱ�������ۼ�word
			}
		}

		int st_len = st.size();
		string temp;
		//������ս��
		if (st.empty()) return "/";			//����ڸ�Ŀ¼����ֱ�ӷ���"/"
		while (!st.empty()) {
			temp = "/" + st.top();			//�����ÿ�������Ŀ¼ǰҪ����һ��"/"
			ans = temp + ans;				//��Ϊջ�� ����ȳ� ������pop������Ҫ���ں���
			st.pop();
		}
		return ans;
	}

	//solution 2: ������˵Ĵ���
	string simplifyPath(string path) {
		stringstream is(path);
		vector<string> strs;
		string ans = "", tmp = "";
		//��"/"Ϊ�ָ��������������ݽ����ж�
		while (getline(is, tmp, '/')) {
			if (tmp == "" || tmp == ".")
				continue;
			else if (tmp == ".." && !strs.empty())		//�ر�ע��Ҫ��strs��Ϊ�յ�����£�����ᱨ��
				strs.pop_back();
			else if (tmp != "..")
				strs.push_back(tmp);
		}
		for (string str : strs)
			ans += "/" + str;				//��Ϊ����ջ���ʹ�ǰ����Ӽ���
		if (ans.empty())
			return "/";
		return ans;
	}
};
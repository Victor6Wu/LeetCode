//输入一行字符串，以'\n'结尾，以空格或者逗号分割，希望将字符串中的片段取出
//需要用到stringstream和getline函数
#include<sstream>
#include<string>
#include<iostream>
using namespace std;

//以cin作为输入，要明确一点：只用cin的时候，cin是以空格为分割的，不借用getline的话是无法读入一行字符串的
void print1(int sign) {
	string s;
	//情况1，遇到空格就会中断
	if (sign == 1) {
		while (cin >> s) {
			cout << s << endl;
		}
	}
	//情况2，可以输入一整行，以'\n'分割
	if (sign == 2) {
		while (getline(cin, s)) {
			cout << s << endl;
		}
	}
	//情况3，以空格分割，但是最后一段会被忽略，除非最后还有一个分隔符
	if (sign == 3) {
		while (getline(cin, s, ' ')) {
			cout << s << endl;
		}	
	}
}

//以stringstream作为getline的输入，先用string初始化一个stringstream
void print2() {
	string str;		//用于输出
	string str_cin;
	getline(cin, str_cin);	//先将输入整行读入
	stringstream ss;
	ss << str_cin;
	while (getline(ss, str, ','))		//可以指定分隔符
		cout << str << endl;
		//cout << stoi(str) <<endl;    如果想输出整形，需要调用stoi函数，反之有to_string函数
}

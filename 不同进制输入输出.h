//按照十六进制、八进制、二进制输入
//按照十六进制、八进制、二进制输出
#include<bitset>
#include<iostream>
using namespace std;

//十六进制形式输入，转十进制
void input16() {	
	unsigned int x;
	cin >> hex >> x;
	cout << x;
}

//八进制形式输入，转十进制
void input8() {
	unsigned int x;
	cin >> oct >> x;
	cout << x;
}

//十六进制形式输出
void output16() {
	unsigned int x;
	cin >> x;
	cout << hex << x;
}

//八进制形式输出
void output8() {
	unsigned int x;
	cin >> x;
	cout << oct << x;
}

//二进制输入，用bitset保存；unsinged int/int 输入也可转成2进制
//方法1：读入01字符串
void input2_1() {
	string s;
	cin >> s;
	bitset<8> bits(s);
	cout << bits;
}

//方法2：直接读入bitset
void input2_2() {
	bitset<8> bits;
	cin >> bits;
	cout << bits;
}

//二进制输出，直接输出bitset，或者经过bitset转成string输出
void output2() {
	unsigned int x;
	cin >> x;
	bitset<32> bits(x);
	cout << bits << endl;
	cout << bits.to_string();
}

//二进制输入，十进制输出
void input2_output10() {
	bitset<4> bits;
	cin >> bits;
	cout << bits.to_ulong();
}
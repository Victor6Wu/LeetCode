//����һ���ַ�������'\n'��β���Կո���߶��ŷָϣ�����ַ����е�Ƭ��ȡ��
//��Ҫ�õ�stringstream��getline����
#include<sstream>
#include<string>
#include<iostream>
using namespace std;

//��cin��Ϊ���룬Ҫ��ȷһ�㣺ֻ��cin��ʱ��cin���Կո�Ϊ�ָ�ģ�������getline�Ļ����޷�����һ���ַ�����
void print1(int sign) {
	string s;
	//���1�������ո�ͻ��ж�
	if (sign == 1) {
		while (cin >> s) {
			cout << s << endl;
		}
	}
	//���2����������һ���У���'\n'�ָ�
	if (sign == 2) {
		while (getline(cin, s)) {
			cout << s << endl;
		}
	}
	//���3���Կո�ָ�������һ�λᱻ���ԣ����������һ���ָ���
	if (sign == 3) {
		while (getline(cin, s, ' ')) {
			cout << s << endl;
		}	
	}
}

//��stringstream��Ϊgetline�����룬����string��ʼ��һ��stringstream
void print2() {
	string str;		//�������
	string str_cin;
	getline(cin, str_cin);	//�Ƚ��������ж���
	stringstream ss;
	ss << str_cin;
	while (getline(ss, str, ','))		//����ָ���ָ���
		cout << str << endl;
		//cout << stoi(str) <<endl;    �����������Σ���Ҫ����stoi��������֮��to_string����
}

//����ʮ�����ơ��˽��ơ�����������
//����ʮ�����ơ��˽��ơ����������
#include<bitset>
#include<iostream>
using namespace std;

//ʮ��������ʽ���룬תʮ����
void input16() {	
	unsigned int x;
	cin >> hex >> x;
	cout << x;
}

//�˽�����ʽ���룬תʮ����
void input8() {
	unsigned int x;
	cin >> oct >> x;
	cout << x;
}

//ʮ��������ʽ���
void output16() {
	unsigned int x;
	cin >> x;
	cout << hex << x;
}

//�˽�����ʽ���
void output8() {
	unsigned int x;
	cin >> x;
	cout << oct << x;
}

//���������룬��bitset���棻unsinged int/int ����Ҳ��ת��2����
//����1������01�ַ���
void input2_1() {
	string s;
	cin >> s;
	bitset<8> bits(s);
	cout << bits;
}

//����2��ֱ�Ӷ���bitset
void input2_2() {
	bitset<8> bits;
	cin >> bits;
	cout << bits;
}

//�����������ֱ�����bitset�����߾���bitsetת��string���
void output2() {
	unsigned int x;
	cin >> x;
	bitset<32> bits(x);
	cout << bits << endl;
	cout << bits.to_string();
}

//���������룬ʮ�������
void input2_output10() {
	bitset<4> bits;
	cin >> bits;
	cout << bits.to_ulong();
}
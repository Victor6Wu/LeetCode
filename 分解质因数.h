//������Լ�������ܹ�����һ�����ĳ��������Ǹ���������
//�������������������������������ٷֽ�
//��һ���������ֽ���������������1�����磺90 = 2 * 3 * 3 * 5
#include<iostream>
using namespace std;

//ע�⣬�˴��Ƿֽ�������������������е�������Լ����
//����������е���������Ҫ��while����if��ɾ��num /= i
void decompose() {
	int num;
	cin >> num;
	cout << num << " = ";
	//��2��ʼ���ԣ������num����
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			cout << i;
			num /= i;
			if (num != 1) {
				cout << " * ";
			}
		}
	}
	cout << endl;
	return;
}
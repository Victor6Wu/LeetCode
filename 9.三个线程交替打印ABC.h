//ע��ǿ�����ǽ����ӡABCABCABC...��˳������
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
int flag = 0;		//��ӡ�ı�־

void printA() {
	unique_lock<mutex> lck(mtx);
	//��ӡ20��A
	for (int i = 0; i < 20; i++) {
		while (flag != 0) {
			cv.wait(lck);
		}
		cout << 'A' << endl;
		flag = 1;
		cv.notify_all();
	}
	cout << "PrintA finished." << endl;
}

void printB() {
	unique_lock<mutex> lck(mtx);
	//��ӡ20��B
	for (int i = 0; i < 20; i++) {
		while (flag != 1) {
			cv.wait(lck);
		}
		cout << 'B' << endl;
		flag = 2;
		cv.notify_all();
	}
	cout << "PrintB finished." << endl;
}

void printC() {
	unique_lock<mutex> lck(mtx);
	//��ӡ20��C
	for (int i = 0; i < 20; i++) {
		while (flag != 2) {
			cv.wait(lck);
		}
		cout << 'C' << endl;
		flag = 0;
		cv.notify_all();
	}
	cout << "PrintC finished." << endl;
}

//int main() {
//	thread thd1(printA), thd2(printB), thd3(printC);
//	thd1.join();
//	thd2.join();
//	thd3.join();
//	return 0;
//}
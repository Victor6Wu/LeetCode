//注意强调的是交替打印ABCABCABC...，顺序不能乱
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
int flag = 0;		//打印的标志

void printA() {
	unique_lock<mutex> lck(mtx);
	//打印20个A
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
	//打印20个B
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
	//打印20个C
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
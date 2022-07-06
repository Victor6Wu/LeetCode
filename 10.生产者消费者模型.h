#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;

mutex mtx;				//ȫ�ֻ�����
queue<int> que;			//ȫ����Ϣ����
condition_variable cv;	//ȫ����������
int cnt = 1;			//����	
int MaxSize = 100;		//��Ϣ������󳤶�
int flag = 1;

void producer() {
	while (true) {
		unique_lock<mutex> lck(mtx);
		while (que.size() >= MaxSize) { 
			cout << "��������" << endl; 
			cv.wait(lck);
		}
		que.push(cnt);
		cout << "�������������ݣ�" << cnt++ << endl;
		//cout << "���д�С��" << que.size() << endl;
		cv.notify_all();
	}
}

void consumer1() {
	while (true) {
		unique_lock<mutex> lck(mtx);
		while (que.size() == 0 || flag == 2) {	// �����ֹ������ٻ���  �����ڻ��Ѻ����ж�һ��
			cv.wait(lck);
		}
		int tmp = que.front();
		cout << "CUN1�Ӷ�����ȡ�����ݣ�" << tmp << endl;
		que.pop();
		flag = 2;
		//cout << "���д�С��" << que.size() << endl;
		cv.notify_all();
	}
}

void consumer2() {
	while (true) {
		unique_lock<mutex> lck(mtx);
		while (que.size() == 0 || flag == 1) {	// �����ֹ������ٻ���  �����ڻ��Ѻ����ж�һ��
			cv.wait(lck);
		}
		int tmp = que.front();
		cout << "CUN2�Ӷ�����ȡ�����ݣ�" << tmp << endl;
		que.pop();
		flag = 1;
		//cout << "���д�С��" << que.size() << endl;
		cv.notify_all();
	}
}
//int main() {
//	thread thd1(producer), thd2(consumer1), thd3(consumer2);
//	thd1.join();
//	thd2.join();
//	return 0;
//}
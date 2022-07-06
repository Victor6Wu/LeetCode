#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;

mutex mtx;				//全局互斥锁
queue<int> que;			//全局消息队列
condition_variable cv;	//全局条件变量
int cnt = 1;			//数据	
int MaxSize = 100;		//消息队列最大长度
int flag = 1;

void producer() {
	while (true) {
		unique_lock<mutex> lck(mtx);
		while (que.size() >= MaxSize) { 
			cout << "队列已满" << endl; 
			cv.wait(lck);
		}
		que.push(cnt);
		cout << "向队列中添加数据：" << cnt++ << endl;
		//cout << "队列大小：" << que.size() << endl;
		cv.notify_all();
	}
}

void consumer1() {
	while (true) {
		unique_lock<mutex> lck(mtx);
		while (que.size() == 0 || flag == 2) {	// 这里防止出现虚假唤醒  所以在唤醒后再判断一次
			cv.wait(lck);
		}
		int tmp = que.front();
		cout << "CUN1从队列中取出数据：" << tmp << endl;
		que.pop();
		flag = 2;
		//cout << "队列大小：" << que.size() << endl;
		cv.notify_all();
	}
}

void consumer2() {
	while (true) {
		unique_lock<mutex> lck(mtx);
		while (que.size() == 0 || flag == 1) {	// 这里防止出现虚假唤醒  所以在唤醒后再判断一次
			cv.wait(lck);
		}
		int tmp = que.front();
		cout << "CUN2从队列中取出数据：" << tmp << endl;
		que.pop();
		flag = 1;
		//cout << "队列大小：" << que.size() << endl;
		cv.notify_all();
	}
}
//int main() {
//	thread thd1(producer), thd2(consumer1), thd3(consumer2);
//	thd1.join();
//	thd2.join();
//	return 0;
//}
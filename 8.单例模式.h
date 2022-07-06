#include<mutex>
//#include<pthread.h>
//优缺点：饿汉模式不用加锁，效率高；懒汉模式只有用的时候才会实例化，不会提前占用空间，相对来说不浪费内存。

//1.经典的线程安全懒汉模式，使用双检测锁模式
class Single1 {
private:
	//私有化构造函数
	static Single1* p;
	//静态锁，是由于静态函数只能访问静态成员
	static pthread_mutex_t lock;
	//私有化构造函数
	Single1() {
		pthread_mutex_init(&lock, NULL);
	}
	~Single1(){}
public:
	//公有静态方法获取实例
	static Single1* getInstance();
};
pthread_mutex_t Single1::lock;
Single1* Single1::p = NULL;
Single1* Single1::getInstance() {
	if (p == NULL) {
		pthread_mutex_lock(&lock);
		if (p == NULL) {
			p = new Single1();
		}
		pthread_mutex_unlock(&lock);
	}
	return p;
}

//2.局部静态变量之线程安全懒汉模式
class Single2 {
private:
	Single2(){}
	~Single2(){}
public:
	static Single2* getInstance();
};
Single2* Single2::getInstance() {
	static Single2 obj;
	return &obj;
}

//3.饿汉模式
class Single3 {
private:
	static Single3* p;
	Single3() {}
	~Single3(){}
public:
	static Single3* getInstance();
};
Single3* Single3::p = new Single3();
Single3* Single3::getInstance() {
	return p;
}

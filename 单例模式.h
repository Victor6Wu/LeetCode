#include<mutex>
//#include<pthread.h>
//��ȱ�㣺����ģʽ���ü�����Ч�ʸߣ�����ģʽֻ���õ�ʱ��Ż�ʵ������������ǰռ�ÿռ䣬�����˵���˷��ڴ档

//1.������̰߳�ȫ����ģʽ��ʹ��˫�����ģʽ
class Single1 {
private:
	//˽�л����캯��
	static Single1* p;
	//��̬���������ھ�̬����ֻ�ܷ��ʾ�̬��Ա
	static pthread_mutex_t lock;
	//˽�л����캯��
	Single1() {
		pthread_mutex_init(&lock, NULL);
	}
	~Single1(){}
public:
	//���о�̬������ȡʵ��
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

//2.�ֲ���̬����֮�̰߳�ȫ����ģʽ
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

//3.����ģʽ
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

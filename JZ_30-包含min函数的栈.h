//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У�
//���� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��
#include<stack>
using namespace std;

class MinStack1 {
private:
    stack<int> mainStk, minStk;
public:
    /** initialize your data structure here. */
    MinStack1() {

    }

    void push(int x) {
        mainStk.push(x);
        if (minStk.empty()) minStk.push(x);
        else {
            int stkTop = minStk.top();
            if (x < stkTop) minStk.push(x);
            else minStk.push(stkTop);
        }
    }

    void pop() {
        mainStk.pop();
        minStk.pop();
    }

    int top() {
        return mainStk.top();
    }

    int min() {
        return minStk.top();
    }
};

//�����ռ��Ż��������ظ��洢��Сֵ
class MinStack2 {
private:
    stack<int> mainStk, minStk;
public:
    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        mainStk.push(x);
        if (minStk.empty() || x <= minStk.top()) minStk.push(x);    //�˴��� <= ����Ҫ�������� < 
    }

    void pop() {
        if (mainStk.top() == minStk.top()) {
            minStk.pop();
        }
        mainStk.pop();
    }

    int top() {
        return mainStk.top();
    }

    int min() {
        return minStk.top();
    }
};
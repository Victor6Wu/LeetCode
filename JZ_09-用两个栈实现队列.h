//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 - 1)

#include<stack>
using namespace std;

class CQueue {
private:
    stack<int> A, B;
public:
    CQueue() {

    }

    void appendTail(int value) {
        A.push(value);
    }

    int deleteHead() {
        if (B.empty()) {
            while (!A.empty()) {
                B.push(A.top());
                A.pop();
            }
        }
        if (B.empty()) return -1;
        int head = B.top();
        B.pop();
        return head;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
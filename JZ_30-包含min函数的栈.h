//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
//调用 min、push 及 pop 的时间复杂度都是 O(1)。
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

//辅助空间优化，避免重复存储最小值
class MinStack2 {
private:
    stack<int> mainStk, minStk;
public:
    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        mainStk.push(x);
        if (minStk.empty() || x <= minStk.top()) minStk.push(x);    //此处的 <= 很重要，不能用 < 
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
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
//但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
#include<vector>
#include<stack>
using namespace std;

//本题的关键在于分析出pop出错会发生在什么位置：“连续”push的结果必须按照倒叙pop，先后顺序不可颠倒
//模拟法，模拟所有的push情况，而在某些push后可能会紧跟若干个pop
//完成了所有的push后，按顺序pop出栈中的值，理论上应该符号popped数组中剩余的部分
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
            i++;
        }

        //挨个pop栈中剩余元素，如果与popped数组剩余部分不能一一对应，则说明false
        while (!stk.empty()) {
            if (stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
            else return false;
        }
        return true;
    }
};
//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//若队列为空，pop_front 和 max_value 需要返回 -1
#include<queue>
using namespace std;

//方法1：借鉴59-I的思路，维护一个单调递减双端队列，以实现快速获得max_value
class MaxQueue1 {
private:
    //先序号，后值，其实不维护序号也可以，pop的时候只需要判断q2的首元素是不是q1的首元素即可
    queue<pair<int, int>> q1;   //单端队列，实现实际的一端入一端出
    deque<pair<int, int>> q2;   //维护q1的同时，维护单调递减的双端队列q2
    int index;                  //用于记录value的插入顺序
public:
    MaxQueue1() : index(0) {

    }

    //时间复杂度O(1)
    int max_value() {
        if (q2.empty()) return -1;
        return q2.front().second;
    }

    //最坏的时间复杂度O(N)：前面的元素全部满足单调递减，此时value大于前面所有元素；
    //最好时间复杂度O(1)
    void push_back(int value) {
        while (!q2.empty() && q2.back().second <= value) q2.pop_back();     //维护单调递减性
        q2.push_back(make_pair(index, value));
        q1.push(make_pair(index, value));
        index++;        //更新index，用于下一个value
    }

    //时间复杂度O(1)
    int pop_front() {
        if (q1.empty()) return -1;
        int ans = q1.front().second;
        int seq = q1.front().first;
        q1.pop();
        //根据q2的维护规则，q2的长度一定小于等于q1，所以只需要判断q2的首元素是否对应q1的首元素，如果是则弹出即可，不需要while
        //其实!q2.empty()可以删去，因为q1非空表明q2至少有一个元素；
        if (!q2.empty() && q2.front().first <= seq)  q2.pop_front();
        return ans;
    }
};

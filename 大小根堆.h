
#include<queue>
#include<vector>
using namespace std;

//1.创建大根堆，属于默认方式：
priority_queue<int> que;
//等价于
priority_queue<int, vector<int>, less<int> > que;

//2.小根堆
priority_queue<int, vector<int>, greater<int> > que;


//根据自己的输入类型，建立优先队列
// 3.重载 < 运算符，实现大顶堆
//（堆顶元素：先根据x，选择x最大的元素；若两个元素的x值相同，再根据y，选择两者中y较大的元素） 
bool operator < (My_Type a, My_Type b)
{
    // 定义排序规则 
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
// 定义优先队列
priority_queue<My_Type> que;

// 4.仿函数，实现大顶堆 
struct cmp
{
    // 定义排序规则 
    bool operator() (My_Type a, My_Type b)
    {
        if (a.x == b.x)return a.y < b.y;
        return a.x < b.x;
    }
};
// 定义优先队列
priority_queue<My_Type, vector<My_Type>, cmp> que;
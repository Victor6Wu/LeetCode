#include<queue>
using namespace std;

//正确解法1：将数据分成较大一半和较小一半，维护一个小根堆和一个大根堆分布存储，维护两个堆的尺寸大小
//addNum的时间复杂度就是O(logN)：堆的插入和弹出操作使用 O(log N)时间。
//findMedian的时间复杂度是O(1)
class MedianFinder1 {
private:
    priority_queue<int, vector<int>, greater<int>> A;   //A较大的一半，采用小根堆
    priority_queue<int, vector<int>, less<int>> B;      //B较小的一半，采用大根堆
    int m, n;
public:
    /** initialize your data structure here. */
    MedianFinder1() {
        m = 0;
        n = 0;
    }
    //始终维持0 <= m - n <= 1
    void addNum(int num) {
        if (m == n) {    //要往A中增添元素
            B.push(num);
            A.push(B.top());
            B.pop();
            m++;
        }
        else {          //要往B中增添元素
            A.push(num);
            B.push(A.top());
            A.pop();
            n++;
        }
    }

    double findMedian() {
        if (m == n) return (A.top() + B.top()) / 2.0;
        else return A.top();
    }
};

//超时写法2：维护一个数组，每次插入都进行排序，时间复杂度就是排序的复杂度O(NlogN)
class MedianFinder2 {
private:
    vector<int> nums;
    int count;
public:
    /** initialize your data structure here. */
    MedianFinder2() {
        nums = {};
        count = 0;
    }

    void addNum(int num) {
        nums.push_back(num);
        count++;
        sort(nums.begin(), nums.end());
    }

    double findMedian() {
        int mid = (count - 1) / 2;
        if (count % 2 == 0) {
            return (nums[mid] + nums[mid + 1]) / 2.0;
        }
        else {
            return nums[mid];
        }
    }
};

//方法3：采用链表保存输入的数据，那么addNum的时间复杂的是O(N)，findMedian的时间复杂度是O(N)
//
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
//自编代码，利用set
class MedianFinder {
public:
    multiset<int> arr;
    MedianFinder() {
    }

    void addNum(int num) {
        arr.insert(num);
    }

    double findMedian() {
        if (arr.empty()) return NULL;
        int n = arr.size();
        auto it = arr.begin();
        if (n % 2 == 0) {
            int count = n / 2 - 1;
            while (count > 0) {
                it++;
                count--;
            }
            int pre = *(it++);
            int cur = *it;
            return (pre + cur) / 2.0;
        }
        else {
            int count = (n - 1) / 2;
            while (count > 0) {
                it++;
                count--;
            }
            return *it;
        }
    }
};

//solution 1：优先队列法，维护一个大根堆记录小于等于中位数的数；一个小根堆记录大于中位数的数；总的保持两个根堆的数量相差不过1
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMIN;
    priority_queue<int, vector<int>, greater<int>> queMAX;

    MedianFinder() {}

    void addNum(int num) {
        //插入无非就两种情况，往queMIN和queMAX插入
        //重点在于考虑什么时候要移动堆顶的元素：始终保证queMIN.size-queMAX.size<=1
        if (queMIN.empty() || num <= queMIN.top()) {
            queMIN.push(num);
            //需要考虑将queMIN的堆顶移动到queMAX：queMIN数量比queMAX多
            if (queMIN.size() - 1 > queMAX.size()) {
                queMAX.push(queMIN.top());
                queMIN.pop();
            }
        }
        else {
            queMAX.push(num);
            //需要考虑将queMAX的堆顶移动到queMIN：queMAX数量比queMIN多
            if (queMAX.size() > queMIN.size()) {
                queMIN.push(queMAX.top());
                queMAX.pop();
            }
        }

    }

    double findMedian() {
        //判断两个堆的数量关系
        if (queMIN.size() > queMAX.size()) {
            return queMIN.top();
        }
        return (queMIN.top() + queMAX.top()) / 2.0;
    }
};

//solution 2:有序集合+双指针:主题思路和solution 1相似，都是一直维护着插入新数前的中位数，根据不同的插入情况，修改当前的中位数
class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder():left(nums.begin()),right(nums.end()){}

    void addNum(int num) {
        const size_t n = nums.size();
        nums.insert(num);
        if (!n) {       //如果插入前集合为空
            left = right = nums.begin();
        }
        else if (n % 2 == 0) {          //偶数情况
            if (num > * left && num < *right) {
                left++;
                right--;
            }
            else if (num <= *left) {
                right--;
                left = right;       //防止num == *left的情况，是的num插在left的右侧
            }
            else {
                left++;
            }
        }
        else {          //奇数情况
            if (num < *left) {
                left--;
            }
            else {
                right++;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};

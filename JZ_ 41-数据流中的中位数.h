#include<queue>
using namespace std;

//��ȷ�ⷨ1�������ݷֳɽϴ�һ��ͽ�Сһ�룬ά��һ��С���Ѻ�һ������ѷֲ��洢��ά�������ѵĳߴ��С
//addNum��ʱ�临�ӶȾ���O(logN)���ѵĲ���͵�������ʹ�� O(log N)ʱ�䡣
//findMedian��ʱ�临�Ӷ���O(1)
class MedianFinder1 {
private:
    priority_queue<int, vector<int>, greater<int>> A;   //A�ϴ��һ�룬����С����
    priority_queue<int, vector<int>, less<int>> B;      //B��С��һ�룬���ô����
    int m, n;
public:
    /** initialize your data structure here. */
    MedianFinder1() {
        m = 0;
        n = 0;
    }
    //ʼ��ά��0 <= m - n <= 1
    void addNum(int num) {
        if (m == n) {    //Ҫ��A������Ԫ��
            B.push(num);
            A.push(B.top());
            B.pop();
            m++;
        }
        else {          //Ҫ��B������Ԫ��
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

//��ʱд��2��ά��һ�����飬ÿ�β��붼��������ʱ�临�ӶȾ�������ĸ��Ӷ�O(NlogN)
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

//����3��������������������ݣ���ôaddNum��ʱ�临�ӵ���O(N)��findMedian��ʱ�临�Ӷ���O(N)
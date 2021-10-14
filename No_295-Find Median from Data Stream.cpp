//
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
//�Ա���룬����set
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

//solution 1�����ȶ��з���ά��һ������Ѽ�¼С�ڵ�����λ��������һ��С���Ѽ�¼������λ���������ܵı����������ѵ���������1
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMIN;
    priority_queue<int, vector<int>, greater<int>> queMAX;

    MedianFinder() {}

    void addNum(int num) {
        //�����޷Ǿ������������queMIN��queMAX����
        //�ص����ڿ���ʲôʱ��Ҫ�ƶ��Ѷ���Ԫ�أ�ʼ�ձ�֤queMIN.size-queMAX.size<=1
        if (queMIN.empty() || num <= queMIN.top()) {
            queMIN.push(num);
            //��Ҫ���ǽ�queMIN�ĶѶ��ƶ���queMAX��queMIN������queMAX��
            if (queMIN.size() - 1 > queMAX.size()) {
                queMAX.push(queMIN.top());
                queMIN.pop();
            }
        }
        else {
            queMAX.push(num);
            //��Ҫ���ǽ�queMAX�ĶѶ��ƶ���queMIN��queMAX������queMIN��
            if (queMAX.size() > queMIN.size()) {
                queMIN.push(queMAX.top());
                queMAX.pop();
            }
        }

    }

    double findMedian() {
        //�ж������ѵ�������ϵ
        if (queMIN.size() > queMAX.size()) {
            return queMIN.top();
        }
        return (queMIN.top() + queMAX.top()) / 2.0;
    }
};

//solution 2:���򼯺�+˫ָ��:����˼·��solution 1���ƣ�����һֱά���Ų�������ǰ����λ�������ݲ�ͬ�Ĳ���������޸ĵ�ǰ����λ��
class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder():left(nums.begin()),right(nums.end()){}

    void addNum(int num) {
        const size_t n = nums.size();
        nums.insert(num);
        if (!n) {       //�������ǰ����Ϊ��
            left = right = nums.begin();
        }
        else if (n % 2 == 0) {          //ż�����
            if (num > * left && num < *right) {
                left++;
                right--;
            }
            else if (num <= *left) {
                right--;
                left = right;       //��ֹnum == *left��������ǵ�num����left���Ҳ�
            }
            else {
                left++;
            }
        }
        else {          //�������
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

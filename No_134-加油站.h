//��һ����·���� N ������վ�����е� i ������վ������ gas[i] ����
//����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� cost[i] ����
//������е�һ������վ��������ʼʱ����Ϊ�ա�
//���������ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� -1��
#include<vector>
using namespace std;

//����1��������
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //ѭ��ÿ������Ϊ�������
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();
            while (rest >= 0 && index != i) {
                rest += (gas[index] - cost[index]);
                index = (index + 1) % gas.size();
            }
            //���ѭ���ܹ���������
            if (index == i && rest >= 0) return i;
        }
        return -1;
    }
};

//����2��ȫ�ֿ���
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT_MAX; // �����������������������Сֵ
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min) {
                min = curSum;
            }
        }
        if (curSum < 0) return -1;  // ���1
        if (min >= 0) return 0;     // ���2
                                    // ���3
        for (int i = gas.size() - 1; i >= 0; i--) {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0) {
                return i;
            }
        }
        return -1;
    }
};

//����3��̰�ķ�
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum = 0;
        int curSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalSum += (gas[i] - cost[i]);
            curSum += (gas[i] - cost[i]);
            if (curSum < 0) {
                curSum = 0;         //������С����Ҫ���¼���
                start = i + 1;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};
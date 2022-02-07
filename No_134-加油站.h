//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
//你从其中的一个加油站出发，开始时油箱为空。
//如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
#include<vector>
using namespace std;

//方法1：暴力法
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //循环每个点作为起点的情况
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();
            while (rest >= 0 && index != i) {
                rest += (gas[index] - cost[index]);
                index = (index + 1) % gas.size();
            }
            //如果循环能够正常结束
            if (index == i && rest >= 0) return i;
        }
        return -1;
    }
};

//方法2：全局考虑
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT_MAX; // 从起点出发，油箱里的油量最小值
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min) {
                min = curSum;
            }
        }
        if (curSum < 0) return -1;  // 情况1
        if (min >= 0) return 0;     // 情况2
                                    // 情况3
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

//方法3：贪心法
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
                curSum = 0;         //余量和小于零要重新计数
                start = i + 1;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};
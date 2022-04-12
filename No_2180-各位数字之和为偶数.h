//给你一个正整数 num ，请你统计并返回 小于或等于 num 且各位数字之和为 偶数 的正整数的数目。
//正整数的 各位数字之和 是其所有位上的对应数字相加的结果。
#include<vector>
using namespace std;

//动态规划法
class Solution {
public:
    bool isOven(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return (sum % 2) == 0 ? true : false;
    }

    int countEven(int num) {
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 1; i <= num; i++) {
            if (isOven(i)) dp[i] = dp[i - 1] + 1;
            else dp[i] = dp[i - 1];
        }
        return dp[num];
    }
};

//动态规划的思想，但是空间复杂度O(1)即可
class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 2; i <= num; i++) {
            if (check(i))res++;
        }
        return res;
    }

public:
    bool check(int num) {
        int checkNum = 0;
        while (num > 0) {
            checkNum = checkNum + (num % 10);
            num /= 10;
        }
        return checkNum % 2 == 0;
    }
};
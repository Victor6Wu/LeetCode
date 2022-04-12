//多重背包问题转换成0-1背包即可
#include<vector>
#include <iostream>
using namespace std;

void test_multi_pack() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    vector<int> nums = { 2, 3, 2 };
    int bagWeight = 10;
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] > 1) { // nums[i]保留到1，把其他物品都展开
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }

    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        for (int j = 0; j <= bagWeight; j++) {
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    cout << dp[bagWeight] << endl;

}
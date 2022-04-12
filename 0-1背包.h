//直观的0-1背包问题
#include<vector>
#include <iostream>
using namespace std;

//二维数组
void test_2_wei_bag_problem1() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagweight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化，第一行，对于物品0，不同容量的情况
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for (int i = 1; i < weight.size(); i++) { // 遍历物品
        for (int j = 0; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}


//一维（滚动）数组
void test_1_wei_bag_problem() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    //循环的嵌套顺序不可改变，必须是先遍历物品，内部遍历背包容量
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量，注意此处的j是倒序遍历
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}
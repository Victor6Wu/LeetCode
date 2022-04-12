//ֱ�۵�0-1��������
#include<vector>
#include <iostream>
using namespace std;

//��ά����
void test_2_wei_bag_problem1() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagweight = 4;

    // ��ά����
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // ��ʼ������һ�У�������Ʒ0����ͬ���������
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight����Ĵ�С ������Ʒ����
    for (int i = 1; i < weight.size(); i++) { // ������Ʒ
        for (int j = 0; j <= bagweight; j++) { // ������������
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}


//һά������������
void test_1_wei_bag_problem() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bagWeight = 4;

    // ��ʼ��
    vector<int> dp(bagWeight + 1, 0);
    //ѭ����Ƕ��˳�򲻿ɸı䣬�������ȱ�����Ʒ���ڲ�������������
    for (int i = 0; i < weight.size(); i++) { // ������Ʒ
        for (int j = bagWeight; j >= weight[i]; j--) { // ��������������ע��˴���j�ǵ������
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}
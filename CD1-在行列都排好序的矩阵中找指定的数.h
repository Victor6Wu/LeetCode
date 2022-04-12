//输入描述：
//第一行有三个整数N, M, K
//接下来N行，每行M个整数为输入的矩阵
//输出描述：
//若K存在于矩阵中输出"Yes"，否则输出"No"
#include<iostream>
#include<vector>
using namespace std;


void solution() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> vec(N, vector<int>(M, 0));
    vector<int> tmp(M, 0);
    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            if (num == K) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}
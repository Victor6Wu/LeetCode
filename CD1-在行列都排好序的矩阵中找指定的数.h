//����������
//��һ������������N, M, K
//������N�У�ÿ��M������Ϊ����ľ���
//���������
//��K�����ھ��������"Yes"���������"No"
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
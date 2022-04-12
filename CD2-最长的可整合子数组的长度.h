//�ȸ�������������Ķ��壺���һ������������֮��ÿ�����������Ĳ�ľ���ֵ��Ϊ1�����߸����鳤��Ϊ1���������Ϊ���������顣
//���磬[5, 3, 4, 6, 2]�����Ϊ[2, 3, 4, 5, 6]������ÿ������������ľ���ֵ��Ϊ1�������������Ϊ����������
//����һ������arr, �뷵��������������������ĳ��ȡ����磬[5, 5, 3, 2, 6, 4, 3]����������������Ϊ[5, 3, 2, 6, 4]�������뷵��5
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
//����Ĺؼ��ǲ�Ҫ�������������Ҫ���ݿ�����������ص�����⣺����ǿ��������飬��ô���еģ�max-min��Ӧ�õ��ڣ����鳤��-1��
//�����㣨max-min�����ڣ����鳤��-1����������˿��������飬����һ�ֿ��ܣ��м����ظ�Ԫ��

void solution() {
    int n, num;
    cin >> n;
    if (n <= 1) {
        cout << n;
        return;
    }
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num;
        vec[i] = num;
    }

    unordered_set<int> nums;
    int res = 1;
    for (int i = 0; i < n; i++) {
        int minN = INT_MAX, maxN = 0;
        for (int j = i; j < n; j++) {
            if (nums.find(vec[j]) != nums.end())
                break;
            nums.insert(vec[j]);
            minN = min(minN, vec[j]);
            maxN = max(maxN, vec[j]);
            if (maxN - minN == j - i) res = max(res, j - i + 1);
        }
        nums.clear();
    }
    cout << res;
    return;
}
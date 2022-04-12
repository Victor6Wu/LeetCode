//先给出可整合数组的定义：如果一个数组在排序之后，每相邻两个数的差的绝对值都为1，或者该数组长度为1，则该数组为可整合数组。
//例如，[5, 3, 4, 6, 2]排序后为[2, 3, 4, 5, 6]，符合每相邻两个数差的绝对值都为1，所以这个数组为可整合数组
//给定一个数组arr, 请返回其中最大可整合子数组的长度。例如，[5, 5, 3, 2, 6, 4, 3]的最大可整合子数组为[5, 3, 2, 6, 4]，所以请返回5
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
//这题的关键是不要进行排序操作，要根据可整合数组的特点来求解：如果是可整合数组，那么其中的（max-min）应该等于（数组长度-1）
//而满足（max-min）等于（数组长度-1）的情况除了可整合数组，还有一种可能：中间有重复元素

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
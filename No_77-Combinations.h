//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。可以按照任意顺序返回
#include<vector>
using namespace std;

//方法：回溯法
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(int n, int k, int startIndex) {
        //终止条件
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            tmp.push_back(i);       //处理节点
            backtracking(n, k, i + 1); //递归
            tmp.pop_back();         //撤销处理节点
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

//回溯法优化，去除那些根本不用考虑的，修改了for循环的终止条件
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(int n, int k, int startIndex) {
        //终止条件
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (int i = startIndex; i <= n - (k - tmp.size()) + 1; i++) {
            tmp.push_back(i);       //处理节点
            backtracking(n, k, i + 1); //递归
            tmp.pop_back();         //撤销处理节点
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
#include<vector>
#include<numeric>
using namespace std;

//方法1：在No_77优化版代码基础上直接修改，不根据本题进行优化
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void backtracking(int k, int startIndex, int n) {
        if (tmp.size() == k) {
            if (accumulate(tmp.begin(), tmp.end(), 0) == n) {
                result.push_back(tmp);
            }
            return;
        }

        for (int i = startIndex; i <= 10 - (k - tmp.size()); i++) {
            tmp.push_back(i);
            backtracking(k, i + 1, n);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, 1, n);
        return result;
    }
};

//方法2：优化，增添一步用于判断tmp中元素和是否已经大于n
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void backtracking(int k, int startIndex, int n, int sum) {
        if (sum > n) {
            return;
        }

        if (tmp.size() == k) {
            if (sum == n) {
                result.push_back(tmp);
            }
            return;
        }

        for (int i = startIndex; i <= 10 - (k - tmp.size()); i++) {
            //处理节点
            tmp.push_back(i);
            sum += i;
            //递归
            backtracking(k, i + 1, n, sum);
            //撤销节点
            tmp.pop_back();
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        backtracking(k, 1, n, sum);
        return result;
    }
};
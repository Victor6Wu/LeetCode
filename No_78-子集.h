//给你一个整数数组 nums ，数组中的元素互不相同 。返回该数组所有可能的子集（幂集）。
//解集不能包含重复的子集。你可以按任意顺序返回解集。
#include<vector>
using namespace std;

//方法1：自编回溯代码，模仿No_39题的方法1，分成考虑和不考虑该点两种情况。
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp = {};
public:
    void backtracking(vector<int>& nums, int startIndex) {
        if (startIndex = nums.size()) {
            if (tmp.size() != 0) {                  //空集单独考虑，不在递归中进行
                result.push_back(tmp);
            }
            return;
        }

        //不包含该点
        backtracking(nums, startIndex + 1);
        //包含该点
        tmp.push_back(nums[startIndex]);
        backtracking(nums, startIndex + 1);
        tmp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        result.push_back({});
        return result;
    }
};

//方法2：套用模板，关键是在每次递归时就执行push，而不是在终止条件里才考虑
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex >= nums.size()) { // 终止条件可以不加，因为不会进入下面的循环
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
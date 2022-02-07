//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//解集不能包含重复的子集。返回的解集中，子集可以按任意顺序排列。
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex >= nums.size()) { // 终止条件可以不加，因为不会进入下面的循环
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i - 1] == nums[i]) {     //因为已经重新排序了，重复元素是紧挨的
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
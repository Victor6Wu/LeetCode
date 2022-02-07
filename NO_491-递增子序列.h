//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
//数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
 
//方法1：在No_90的代码上进行修改，修改结果收集条件、修改去重方式
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(vector<int>& nums, int startInddex, int endNum) {
        if (tmp.size() >= 2) {
            result.push_back(tmp);
        }
        if (startInddex >= nums.size()) {
            return;
        }
        //uset只负责本层！
        unordered_set<int> uset;            //用set去重，要注意不是在最后的结果去重，那样编译不通过。要在同层去重，即for循环内去重
        for (int i = startInddex; i < nums.size(); i++) {
            if (nums[i] < endNum || uset.find(nums[i]) != uset.end()) {        //同层重复的去除；当前点没最后一个大的也不考虑
                continue;
            }
            uset.insert(nums[i]);
            tmp.push_back(nums[i]);
            backtracking(nums, i + 1, nums[i]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        tmp.clear();
        backtracking(nums, 0, INT_MIN);
        return result;
    }
};

//代码优化，将set替换成数组
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(vector<int>& nums, int startInddex, int endNum) {
        if (tmp.size() >= 2) {
            result.push_back(tmp);
        }
        if (startInddex >= nums.size()) {
            return;
        }
        //uset只负责本层！
        vector<bool> uset(201);            //用数组去重，要注意不是在最后的结果去重，那样编译不通过。要在同层去重，即for循环内去重
        for (int i = startInddex; i < nums.size(); i++) {
            if (nums[i] < endNum || uset[nums[i] + 100]) {        //同层重复的去除；当前点没最后一个大的也不考虑
                continue;
            }
            uset[nums[i] + 100] = true;
            tmp.push_back(nums[i]);
            backtracking(nums, i + 1, nums[i]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        tmp.clear();
        backtracking(nums, 0, INT_MIN);
        return result;
    }
};
//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标。
#include<vector>
using namespace std;

//方法1：没遇到一个点就递归其范围内的点，进一步递归，会有很多点被重复访问，超时
class Solution {
public:
    bool jump(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) return true;
        int step = nums[index];
        if (step == 0) return false;
        bool sign = false;
        while (step > 0) {
            sign = (sign || jump(nums, index + step));
            step--;
        }
        return sign;
    }
    bool canJump(vector<int>& nums) {
        return jump(nums, 0);
    }
};

//方法2：这道题目关键点在于：不用拘泥于每次究竟跳跳几步，而是看覆盖范围，覆盖范围内一定是可以跳过来的，不用管是怎么跳的
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);    //更新cover
            if (cover >= nums.size()) return true;
        }
        return false;
    }
};
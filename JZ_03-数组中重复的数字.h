//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
//请找出数组中任意一个重复的数字。
#include<vector>
using namespace std;

class Solution1 {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> count(nums.size(), false);
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]]) {
                ans = nums[i];
                break;
            }
            count[nums[i]] = true;
        }
        return ans;
    }
};

//方法2：空间复杂度O(1)，借用原始的nums数组作为存储出现结果的数组，因为题目条件：数组中的数组属于[0, n)
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            if (k < 0) k += n;      //k < 0 说明之前这个位置索引对应的数值出现过，将该位置的值再加上n，用于找其对应的位置
            if (nums[k] < 0) return k;  //当出现重复时候，访问到nums[k]会发现其已经被置为负数
            nums[k] -= n;
        }

        return -1;
    }
};
//一个长度为n - 1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n - 1之内。
//在范围0～n - 1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
#include<vector>
using namespace std;

//遍历一遍，时间复杂度O(N)
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] != 0) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) continue;
            return nums[i - 1] + 1;
        }
        return n;
    }
};

//二分法：根据题意，数组可以分成两部分：左子数组nums[i] == i; 右子数组nums[i] != i
//只要能找到右子数组的第一个元素对应的索引，即结果。时间复杂度O（logN）
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid) left = mid + 1;   //如果当前位置还是nums[i] == i，说明右子数组还在右边
            else right = mid - 1;       //否则，此时已经落入右子数组内
        }
        return left;
    }
};
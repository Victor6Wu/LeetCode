//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
#include<vector>
using namespace std;

//双指针法，空间复杂度O(N)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[right--] = nums[i];
            }
            else {
                ans[left++] = nums[i];
            }
        }
        return ans;
    }
};

//原地交换1
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] % 2 == 0) {
                swap(nums[left], nums[right]);
                right--;
            }
            else left++;
        }
        return nums;
    }
};

//原地交换2，借鉴快排的思想
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < n && nums[left] % 2 == 1) left++;
            while (right >= 0 && nums[right] % 2 == 0) right--;
            if (left > right) break;
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};
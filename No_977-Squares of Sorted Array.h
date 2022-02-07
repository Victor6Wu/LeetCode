//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
#include<vector>
#include<algorithm>
using namespace std;

//方法1：平方完了再排序，时间复杂度O(nlogn)
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

//方法2：双指针法，找到正负分界线，从中间往两头分别比较大小，插入新数组中
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int divide = 0;             //正负分界线
        for (; divide < nums.size(); divide++) {
            if (nums[divide] >= 0) {
                break;
            }
        }
        int i = divide - 1, j = divide;
        vector<int> ans;
        while (i >= 0 || j < nums.size()) {
            if (i < 0) {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
            else if (j >= nums.size()) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else if ((nums[i] * nums[i]) < (nums[j] * nums[j])) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return ans;
    }
};

//方法3：双指针法，从两端往中间聚集，比谁大，把大的逆序放入数组
class Solution3 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
#include<vector>
#include<unordered_set>
using namespace std;

//方法1，利用hash，空间复杂度O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 1) return {};
        unordered_set<int> q;
        for (int i = 0; i < n; i++) {
            if (q.count(target - nums[i]) != 0)
                return { nums[i], target - nums[i] };
            q.insert(nums[i]);
        }
        return {};
    }
};

//方法2，利用数组已经排序的特点，左右双指针逐渐往中间移动
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 1) return {};
        int left = 0, right = n - 1;
        while (left < right) {
            int tmp = nums[left] + nums[right];     //对于可能溢出的情况，不要同相加的结果去比较大小
            if (tmp == target) return { nums[left], nums[right] };
            else if (tmp > target) right--;
            else left++;
        }
        return {};
    }
};
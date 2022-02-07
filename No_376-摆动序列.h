//给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
#include<vector>
using namespace std;

//贪心法，不断交错的选择“峰”或“谷”，遇到
class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int prevdiff = nums[1] - nums[0];
        int ret = prevdiff != 0 ? 2 : 1;       //如果头两个是相等元素，ret要从1开始计数
        for (int i = 2; i < n; i++) {   
            int diff = nums[i] - nums[i - 1];
            //跳过坡上的过渡元素以及“水平”元素
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                ret++;
                prevdiff = diff;
            }
        }
        return ret;
    }
};

//动态规划法
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            }
            else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

//动态规划优化
class Solution3 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = max(up, down + 1);     //up = down + 1;    在循环的过程中，down和up差值不会大于1
            }
            else if (nums[i] < nums[i - 1]) {
                down = max(up + 1, down);   //down = up + 1;
            }
        }
        return max(up, down);
    }
};
//普通的动态规划问题
//dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i] 
//dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])。
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size(); j > 0; j--) {
                int index = j - 2;
                int maxNum = 0;
                while (index >= 0) {
                    maxNum = max(maxNum, dp[index]);
                    index--;
                }
                dp[j] = max(dp[j - 1], maxNum + nums[i]);
            }
        }
        return dp[nums.size()];
    }
};
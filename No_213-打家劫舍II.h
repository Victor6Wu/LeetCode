//���ӱ��һ������
#include<vector>
using namespace std;

//��̬�滮���������������Ҫ���ǣ�1.������βԪ�أ�2.��������Ԫ�ء�
//��������ڲ�������No_198�ķ�������
class Solution {
public:
    int robCore(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int res1 = robCore(nums, 0, nums.size() - 2);   //���1
        int res2 = robCore(nums, 1, nums.size() - 1);   //���2
        return max(res1, res2);
    }
};
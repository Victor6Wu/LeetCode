//
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

//贪心法，先将最下的一些负数置为负，再考虑是否将最小的非负数反复求相反数。
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int startIndex = 0;
        //先把尽可能多的负数置为正
        while (startIndex < nums.size() && nums[startIndex] < 0 && k > 0) {
            nums[startIndex] = 0 - nums[startIndex];
            startIndex++;
            k--;
        }
        if (k > 0) {     //k有剩余表明此时已经没有负数
            sort(nums.begin(), nums.end());
            k = k % 2;
            if (k == 1) {
                nums[0] = 0 - nums[0];
                k--;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//关键是，先了解什么是字典序
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;    //从倒数第二个元素开始
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {       //成功找到了要交换的较小的数
            int j = nums.size() - 1;
            while (j > 0 && nums[i] >= nums[j]) {      //从后向前找到刚好比nums[i]的第一个元素
                j--;
            }
            swap(nums[i], nums[j]);
        }
        //将nums[i]之后的元素重新排序成升序，因为交换后的部分也仍然是降序，所以 直接reverse即可
        //如果nums本身已经是最大排序，则i会等于-1，整体翻转即可
        reverse(nums.begin() + i + 1, nums.end());
    }
};
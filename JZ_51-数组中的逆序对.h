//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
#include<vector>
using namespace std;

//归并排序法
//本题的结果是在归并排序的过程中累计得出的，必须要弄清楚归并的过程与记录逆序对的关系：
//将数组分成左右两个部分A、B，分别实现了递增的特点，在归并AB的过程中，右侧的B中若有元素比A中的小，那么就“存在着A中剩余元素数量相等的逆序对数”；
//而已经归并完成的数组内部的逆序对数已经统计完毕，再往上一层归并的时候，已经无需考虑内部的元素顺序，只需要重复上一步的工作即可
class Solution {
public:
    void merge(vector<int>& nums, vector<int>& tmp, int L, int R, int& count) {
        if (L >= R) return;
        int mid = L + (R - L) / 2;
        merge(nums, tmp, L, mid, count);
        merge(nums, tmp, mid + 1, R, count);
        int index = L, p1 = L, p2 = mid + 1;
        while (p1 <= mid && p2 <= R) {
            if (nums[p1] <= nums[p2]) tmp[index++] = nums[p1++];
            else {
                tmp[index++] = nums[p2++];
                count += (mid - p1 + 1);        //只有右侧数组中的数比左侧数组的数小的时候统计
            }
        }
        while (p1 <= mid) tmp[index++] = nums[p1++];
        while (p2 <= R) tmp[index++] = nums[p2++];

        for (int i = L; i <= R; i++) {
            nums[i] = tmp[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        vector<int> tmp(nums.size(), 0);
        merge(nums, tmp, 0, nums.size() - 1, count);
        return count;
    }
};
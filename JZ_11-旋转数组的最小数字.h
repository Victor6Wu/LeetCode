//给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。
//例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。 
#include<vector>
using namespace std;

//遍历法
class Solution1 {
public:
    int minArray(vector<int>& numbers) {
        int ans = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] < numbers[i - 1]) ans = numbers[i];
        }
        return ans;
    }
};

//二分查找，难点在于有重复元素的出现会影响查找过程中判断最小值在mid的左侧还是右侧
//平均时间复杂度O(logN)，最坏情况（全部相同的数组）会退化为O(N)
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            //往右查找
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            }
            //往左查找
            else if (numbers[mid] < numbers[right]){
                right = mid;            //注意此处不可以-1，因为mid处可能就是要找的结果了
            }
            //出现了重复值的情况，无法判断下一步是往左还是往右查找，直接将right-1即可，因为right至少有一个替代品mid
            //如：[4,3,4,4,4,4] 和 [4,4,4,4,3,4]
            //对于此次循环而言，相当于退化成暴力遍历；总的来说就是暴力遍历与二分交替进行
            else {
                right--;
            }
        }
        return numbers[left];
    }
};
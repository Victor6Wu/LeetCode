//Given an array nums and a value val, remove all instances of that value in-place and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:原地删除法
	int removeElement1(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		for (auto i = nums.begin(); i != nums.end(); ) {
			if (*i == val) {
				i = nums.erase(i);
			}
			else {
				++i;
			}
		}
		return nums.size();
	}

	//solution 2:最大化+排序
	int removeElement2(vector<int>& nums, int val) {
		if (nums.size() == 0)	return 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == val) nums[i] = INT_MAX;
		}
		sort(nums.begin(), nums.end());
		int j = 0;
		while (j < nums.size() && nums[j] < INT_MAX) {
			++j;
		}
		return j;
	}

	//solution 3:双指针法，从头开始两个指针，一起向右移动
	int removeElement(vector<int>& nums, int val) {
		int left = 0, n = nums.size();				//left初始值为0很重要，最后返回的就是left
		for (int right = 0; right < n; ++right) {
			if (nums[right] != val) {
				nums[left] = nums[right];
				left++;
			}
		}
		return left;
	}

	//solution 4:双指针法优化,指针从首尾开始，向中间汇合，避免了方法3中一些无用的重复工作
	int removeElement(vector<int>& nums, int val) {
		int left = 0, right = nums.size();
		while (left < right) {
			if (nums[left] == val) {
				nums[left] = nums[right - 1];		//用末尾的值覆盖数组头部等于val的值
				--right;							//此时left不变，还需要判断新的nums[left]是否仍然等于val
			}
			//保证所有不等于val的值都可以放在left左侧，等于val的值都会置于left右侧
			else {
				++left;
			}
		}
		return left;
	}
};
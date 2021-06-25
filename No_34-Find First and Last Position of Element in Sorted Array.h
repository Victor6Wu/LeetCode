//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:循环遍历，时间复杂度O(n)
	vector<int> searchRange1(vector<int>& nums, int target) {
		int start_ptr = -1, end_ptr = -1;
		int count = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target && count == 0) {
				start_ptr = i;
				++count;
			}
			else if (nums[i] == target) {
				++count;
			}
		}
		if (start_ptr != -1) {
			end_ptr = start_ptr + count - 1;
		}
		
		return { start_ptr,end_ptr };
	}

	//solution 2:二分查找，时间复杂度O(logn)，思路：要找的其实就是第一个 >=target 的位置，和第一个 >target 的位置
	int binarySearch(vector<int>& nums, int target, bool lower) {	//lower是一个标识符，表示查找>=还是>target的位置
		int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size(); //ans初始值为nums.size(),在searchRange中需要检验是否修改
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] > target || (lower && nums[mid] >= target)) {			//无论大于等于还是大于，要继续往左搜索
				right = mid - 1;
				ans = mid;
			}
			else {			//小于等于或者小于，需要继续往右搜素
				left = mid + 1;
			}
		}
		return ans;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int left_index = binarySearch(nums, target, true);				//找到第一个大于等于的位置
		int right_index = binarySearch(nums, target, false) - 1;		//用上面的函数找到第一个大于的位置
		//判断条件
		if (left_index <= right_index && right_index < nums.size() && nums[left_index] == target && nums[right_index] == target) {
			return {left_index,right_index};
		}
		return { -1,-1 };
	}
};
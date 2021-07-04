//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		int left = 0, right = n - 1;
		int mid = 0;
		while (left < right) {
			int mid = (left + right) / 2;
			if (target == nums[mid]) {
				return mid;
			}
			else if (target > nums[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return target > nums[left] ? left + 1 : left;
	}
};
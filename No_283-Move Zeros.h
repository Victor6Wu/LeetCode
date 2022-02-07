//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return ;
		int slow = 0, fast = 1;
		while (fast < n) {
			if (nums[slow] != 0) {
				slow++;
				fast++;
			}
			else {
				if (nums[fast] != 0) {
					swap(nums[slow], nums[fast]);
				}
				else {
					fast++;
				}
			}
		}
		return;
	}
};
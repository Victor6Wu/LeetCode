//Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:逐个循环，时间复杂度O(n)
	int search1(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target) return i;
		}
		return -1;
	}

	//solution 2:进阶版，二分查找，时间复杂度O(logn)，具体的代码实现有不同的表达方式
	int subSearch(vector<int>& nums, int target, int start, int end) {
		if (start == end) {
			return nums[start] == target ? start : -1;
		}
		int mid = (start + end) / 2;
		int mid_next = mid + 1;
		//优先确认左侧一半是否为有序
		if (nums[start] <= nums[mid]) {
			if (nums[start] <= target && target <= nums[mid]) {
				return subSearch(nums, target, start, mid);
			}
			return subSearch(nums, target, mid_next, end);
		}
		//左侧无序即认为右侧有序
		else {
			if (nums[mid_next] <= target && target <= nums[end]) {
				return subSearch(nums, target, mid_next, end);
			}
			return subSearch(nums, target, start, mid);
		}

	}

	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return -1;
		int ans = subSearch(nums, target, 0, n - 1);
		return ans;
	}

	//solution 3:二分法，代码不采用递归的形式
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (!n)
        {
            return -1;
        }
        if (n == 1)
        {
            return (nums[0] == target) ? 0 : -1;
        }
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
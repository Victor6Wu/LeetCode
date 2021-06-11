//原地对数组排序，不能使用sort函数
#include<vector>
using namespace std;
class Solution {
public:
	//solution 1:起泡排序
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		bool sorted = false;
		for (int i = 0; (i < nums.size()) && (sorted == false); ++i) {
			sorted = true;
			for (int j = 1; j < n; ++j) {
				if (nums[j - 1] > nums[j]) {
					int temp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = temp;
					sorted = false;
				}
			}
			n--;
		}
	}

	//solution 2：双指针,循环两次，第一次把0都换到前面，第二次把1换到0后面的位置
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0;
		while (j < nums.size()) {
			if (nums[j] == 0) {
				swap(nums[i], nums[j]);
				++i;
			}
			++j;
		}
		j = i;
		while (j < nums.size()) {
			if (nums[j] == 1) {
				swap(nums[i], nums[j]);
				++i;
			}
			++j;
		}
	}
};


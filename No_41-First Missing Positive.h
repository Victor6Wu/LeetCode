//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) timeand uses constant extra space.
#include<vector>
#include<algorithm>
using namespace std;

//solution 1:自编代码，用到了排序 
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0;
		while (i < nums.size() && nums[i] <= 0) {
			i++;
		}
		int num = 1;
		while (i < nums.size() && num == nums[i]) {
			i++;
			if (i < nums.size() && nums[i] == nums[i - 1]) {
				continue;
			}
			num++;
		}
		return num;
	}
};

//solution 2:借用哈希表的思想，用数组中索引位置的正负来表示【1，n】中数字的出现情况
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//第一次遍历前应该要先判断数组中有没有出现1，以免出现数组全都是大于n的正数的情况。
		//第一次遍历，将小于等于0，和大于n的数，置为1。处理后整个数组都是正数。
		int sign = 0;		//判断数组中有无1的标志
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) sign = 1;
			if (nums[i] <= 0) {
				nums[i] = 1;
			}
			else if (nums[i] > nums.size()) {
				nums[i] = 1;
			}
		}
		if (sign == 0) return 1;		//如果标志仍为0，说明数组中没有1，返回即可 

		//第二次遍历，根据数字大小将对应索引的数字置为负数，以表明该数字出现过
		//要注意解决重复出现的问题；注意索引是从0开始的问题
		for (int i = 0; i < nums.size(); i++) {
			int num = abs(nums[i]);		//因为该位置的数可能被置为负数，所以只看绝对值
			nums[num - 1] = -abs(nums[num - 1]);
		}

		//第三次遍历，寻找数组中第一个正数，表明数组中没有这个数，使得这个索引处的值为负
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		//如果都是负数，说明数组刚好是【1，n】，结果就为n+1
		return nums.size() + 1;
	}
};

//solution 2+:没必要将大于n的数置为1，因为也找不到它对应的索引；将小于等于0的数置为n+1更好
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//第一次遍历，将所有的非正数置为n+1
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= 0) {
				nums[i] = nums.size() + 1;
			}
		}

		//第二次遍历，根据数字大小将对应索引的数字置为负数，以表明该数字出现过
		//要注意解决重复出现的问题；注意索引是从0开始的问题
		for (int i = 0; i < nums.size(); i++) {
			int num = abs(nums[i]);		//因为该位置的数可能被置为负数，所以只看绝对值
			if (num <= nums.size()) {
				nums[num - 1] = -abs(nums[num - 1]);
			}
		}

		//第三次遍历，寻找数组中第一个正数，表明数组中没有这个数，使得这个索引处的值为负
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		//如果都是负数，说明数组刚好是【1，n】，结果就为n+1
		return nums.size() + 1;
	}
};

//solution 3:置换法，将数字放到应属的位置，倾向于[1,2,...N]的形式，直到当前操作的数不在[1,N]之间，特别注意死循环的情况，一共N个数，最多也就循环N次
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		//找到第一个索引和数值不符的数
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
#include<vector>
#include<algorithm>
using namespace std;

//solution1:借鉴No_31字典序的思路，下一个最大的字典序就是不断地将大的数挪到高位，小的数挪到地位。
class Solution1 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size() - 2;
		vector<vector<int>> res;
		res.push_back(nums);
		bool sign = true;
		while (sign) {
			int i = n;		//从后向前找，找到那个不满足逆序递增趋势的位置
			while (i >= 0 && nums[i] >= nums[i + 1]) {
				i--;
			}
			if (i >= 0) {
				int j = n + 1;
				while (j > 0 && nums[i] >= nums[j]) {		//还是从后向前找，找到刚好比i位置的数大的数
					j--;
				}
				swap(nums[i], nums[j]);
				reverse(nums.begin() + i + 1, nums.end());	//重排后面一部分，使其满足递增趋势
				res.push_back(nums);
			}
			else {			//当整个数组呈递减趋势时已经是最大的字典序，次数i会找到-1，退出即可
				sign = false;
			}
		}
		return res;
	}
};

//solution2:回溯法，将nums的元素往vector中填，关键点在于始终维护的是一个数组，所以要将当前准备填的数和准备填到位置处的数进行交换，
//即已经填了的数挪到数组的左侧，右侧是待填的数
class Solution2 {
public:
	//first表示当前想要填的空
	void backtrack(vector<vector<int>>& res, vector<int>& nums, int first, int len) {
		if (first == len) {
			res.push_back(nums);
			return;
		}
		//对first位置及之后的每个数循环考虑填入当前的first位置
		for (int i = first; i < len; i++) {			//这里关键的一点在于，i是从first开始的，因为first以前的位置已经被填好了，且通过swap操作将这些数放置在位置上了
			//动态维护数组
			swap(nums[i], nums[first]);
			//继续考虑下一个位置
			backtrack(res, nums, first + 1, len);
			//撤销i填入first的操作，考虑i+1填入first
			swap(nums[i], nums[first]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		backtrack(res, nums, 0, (int)nums.size());
		return res;
	}
};

//回溯自写代码，数组中没有重复值，对数组全排序就意味着对所有的索引进行了全排序
class Solution {
private:
	vector<vector<int>> result;
	vector<int> tmp;
public:
	void backtracking(vector<int>& nums, vector<bool> used) {
		if (tmp.size() == nums.size()) {
			result.push_back(tmp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!used[i]) {
				used[i] = true;
				tmp.push_back(nums[i]);
				backtracking(nums, used);
				tmp.pop_back();
				used[i] = false;
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> used(nums.size(), false);		//其实是维护索引有没有被用过
		backtracking(nums, used);
		return result;
	}
};
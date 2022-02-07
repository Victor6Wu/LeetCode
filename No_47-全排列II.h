//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
#include<vector>
#include<algorithm>
using namespace std;

//借用No_46的字典序方法，秒解，不用考虑什么重复的问题
class Solution1 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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

//回溯法1，在No_46的基础上要增添一个同层去重的步骤
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

		vector<bool> usedNum(21, false);		//同层去重，注意后面设置成true后不会再设置回false
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] || usedNum[nums[i] + 10]) {
				continue;
			}
			usedNum[nums[i] + 10] = true;
			used[i] = true;
			tmp.push_back(nums[i]);
			backtracking(nums, used);
			tmp.pop_back();
			used[i] = false;		
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool> used(nums.size(), false);		//维护索引有没有被用过，深度上的去重	
		backtracking(nums, used);				
		return result;
	}
};

//回溯法2，在递归之出就对数组进行排序，这样不需要通过维护usedNum数组的方式也能实现同层去重
class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<bool>& used) {
		// 此时说明找到了一组
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			// used[i - 1] == true，说明同一树枝nums[i - 1]使用过
			// used[i - 1] == false，说明同一树层nums[i - 1]使用过
			// 如果同一树层nums[i - 1]使用过则直接跳过，同一树枝使用过没关系
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {//如果不添加used[i - 1] == false，会影响深度上的递归（即树枝）
				continue;
			}
			if (used[i] == false) {
				used[i] = true;
				path.push_back(nums[i]);
				backtracking(nums, used);
				path.pop_back();
				used[i] = false;
			}
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		result.clear();
		path.clear();
		sort(nums.begin(), nums.end()); // 排序
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return result;
	}
};
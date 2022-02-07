//给定两个数组，编写一个函数来计算它们的交集。
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//方法1：用set写
class Solution1 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> tmp;			//存放结果，不能有重复数值
		unordered_set<int> table(nums1.begin(), nums1.end());
		for (int it : nums2) {
			if (table.find(it) != table.end()) {
				tmp.insert(it);
			}
		}
		return vector<int>(tmp.begin(), tmp.end());
	}
};


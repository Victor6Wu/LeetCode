//给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

//方法1：用multiset，每次找到一个就删除一个
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;		
		multiset<int> table(nums1.begin(), nums1.end());
		for (int it : nums2) {
			auto iter = table.find(it);			//这里注意，要把find的迭代器取出来，后面再删除该迭代器指向的元素
			if (iter != table.end()) {
				ans.push_back(it);
				table.erase(iter);				//不同直接将某个数值删除，这样会将该重复的数值都删除
			}
		}
		return ans;
    }
};

//方法2：用map记录每个数出现的次数
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		unordered_map<int, int> table;
		for (int it : nums1) {
			table[it]++;
		}
		for (int it : nums2) {
			table[it]--;
			if (table[it] >= 0) {
				ans.push_back(it);
			}
		}
		return ans;
	}
};
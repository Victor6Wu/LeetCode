//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
//and return an array of the non-overlapping intervals that cover all the intervals in the input.
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:排序，自编代码，采用哈希表
	vector<vector<int>> merge1(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) return intervals;//小于两个区间可直接返回
		//转成可重复的哈希表
		multimap<int, int> table;
		for (int i = 0; i < intervals.size(); ++i) {
			table.insert({ intervals[i][0],intervals[i][1] });
		}

		//构建两个相邻的迭代器，用于比较区间
		auto next = table.begin();
		auto it = next++;
		while (next != table.end()) {
			//获取两个区间的四个边界
			int left_1 = it->first, right_1 = it->second;
			int left_2 = next->first, right_2 = next->second;

			if (right_1 < left_2) {
				++it;
				++next;
			}
			else if (right_1 <= right_2) {
				it->second = right_2;
				next = table.erase(next);
			}
			else if (right_1 > right_2) {
				next = table.erase(next);
			}
		}

		//将哈希表再转回二维数组
		vector<vector<int>> ans;
		for (auto it = table.cbegin(); it != table.cend(); ++it) {
			ans.push_back({ it->first,it->second });
		}
		return ans;
	}

	//solution 2:排序，官方代码，没采用哈希表，（vector可以直接进行排序的）
	//只需要再用一个vector<vector<int>>存结果，以及对其利用back来取倒数第一个区间与当前考虑的区间进行比较即可
	vector<vector<int>> merge2(vector<vector<int>>& intervals) {
		if (intervals.size() < 2) {
			return intervals;
		}

		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size(); ++i) {
			int left = intervals[i][0], right = intervals[i][1];
			if (ans.empty() || ans.back()[1] < left) {
				ans.push_back({ left,right });
			}
			else {
				ans.back()[1] = max(ans.back()[1], right);
			}
		}
		return ans;
	}
};
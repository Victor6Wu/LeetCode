//A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
//Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	//solution 1:借用有序队列，左边界入堆，右边界出堆，根据堆顶变化与否确定关键点
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//先将输入改成左右边界的形式，区别在于左边界高度用负数表示
		multiset<pair<int, int>> vec;
		for (auto& b : buildings) {
			vec.insert({ b[0],-b[2] });
			vec.insert({ b[1],b[2] });
		}

		//构建“堆”
		multiset<int> Q;
		Q.insert(0);	//先存入初始高度0
		int preMax = 0;	//初始最大值

		vector<vector<int>> res;
		for (auto& it : vec) {		//扫描所有边界
			if (it.second < 0) {	//左边界入堆
				Q.insert(-it.second);	
			}
			else		//右边界出堆
			{
				Q.erase(Q.find(it.second));
			}
			int curMax = *Q.rbegin();
			if (curMax != preMax) {		//最大值发生变化，有关键点产生
				res.push_back({ it.first,curMax });
				preMax = curMax;		//更新之前的最大值
			}
		}
		return res;
	}
};
//每个顾客需求两道菜，用编号表示，每种菜只有一份，求最多可以满足的顾客数量
#include<vector>
#include<iostream>
using namespace std;

//方法：深度优先搜索，每个顾客无非两种情况，考虑与不考虑，用count计数，同时根据菜品，判断能否考虑。
//顾客用vector<pair<int, int>>存储，递归回溯遍历，每次给一个index
//另外用一个vector记录菜品是否被食用

class Solution {
private:
	int ans;
	int count = 0;
public:
	void backtracking(vector<pair<int, int>>& customs, int index, vector<bool>& foods) {
		if (index >= customs.size()) {
			ans = max(ans, count);
		}
		for (int i = index; i < customs.size(); i++) {
			int x = customs[i].first, y = customs[i].second;
			if (foods[x] && foods[y]) {		//如果菜品foods中该菜品还可以食用
				foods[x] = false;
				foods[y] = false;
				count++;
				backtracking(customs, i + 1, foods);
				count--;
				foods[x] = true;
				foods[y] = true;
			}
		}
	}

	void result() {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> customs(n);
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			customs[i] = make_pair(x, y);
		}
		vector<bool> foods(m + 1, true);
		backtracking(customs, 0, foods);
		cout << ans;
	}
};

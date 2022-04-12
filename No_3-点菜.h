//ÿ���˿����������ˣ��ñ�ű�ʾ��ÿ�ֲ�ֻ��һ�ݣ�������������Ĺ˿�����
#include<vector>
#include<iostream>
using namespace std;

//�������������������ÿ���˿��޷���������������벻���ǣ���count������ͬʱ���ݲ�Ʒ���ж��ܷ��ǡ�
//�˿���vector<pair<int, int>>�洢���ݹ���ݱ�����ÿ�θ�һ��index
//������һ��vector��¼��Ʒ�Ƿ�ʳ��

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
			if (foods[x] && foods[y]) {		//�����Ʒfoods�иò�Ʒ������ʳ��
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

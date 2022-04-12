//给可重复集合，从中选出尽可能大的子集使得没有两个数据是“连续的”（连续指两数之差的绝对值不超过1）
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//遍历，贪心法
void solution() {
	int n;
	while (cin >> n) {
		int num;
		vector<int> nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> num;
			nums[i] = num;
		}

		int ans = 0;
		sort(nums.begin(), nums.end());
		int tmpLen = 1;
		int lastNum = nums[0];
		for (int i = 1; i < n; i++) {
			if (nums[i] == nums[i - 1]) continue;
			if (abs(nums[i] - lastNum) >= 2) {
				lastNum = nums[i];
				tmpLen++;
			}
			ans = max(ans, tmpLen);
		}
		cout << ans;
	}
	return;
}

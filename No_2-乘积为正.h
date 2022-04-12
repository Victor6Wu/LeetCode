#include<vector>
#include<iostream>
using namespace std;

void solution() {
	int n;
	cin >> n;
	vector<int> nums(n);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums[i] = num;
	}
	//动态规划法
	vector<int> dp0(n);		//以此数为结尾，乘积为正的子序列数
	vector<int> dp1(n);		//以此数为结尾，乘积为负的子序列数
	if (nums[0] == 1) dp0[0] = 1;
	else dp1[0] = 1;
	for (int i = 1; i < n; i++) {
		if (nums[i] == 1) {
			dp0[i] = dp0[i - 1] + 1;
			dp1[i] = dp1[i - 1];
		}
		else {
			dp0[i] = dp1[i - 1];		//当前是-1，乘积为正的个数只取决于之前是负的个数
			dp1[i] = dp0[i - 1] + 1;	//因为当前是-1，之前为正的再成-1肯定为负，同时-1本身也是负
		}
	}
	int count = 0;
	for (int it : dp0) {
		count += it;
	}
	cout << count << endl;
}
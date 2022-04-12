//�����ظ����ϣ�����ѡ�������ܴ���Ӽ�ʹ��û�����������ǡ������ġ�������ָ����֮��ľ���ֵ������1��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//������̰�ķ�
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

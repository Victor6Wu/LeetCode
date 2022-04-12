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
	//��̬�滮��
	vector<int> dp0(n);		//�Դ���Ϊ��β���˻�Ϊ������������
	vector<int> dp1(n);		//�Դ���Ϊ��β���˻�Ϊ������������
	if (nums[0] == 1) dp0[0] = 1;
	else dp1[0] = 1;
	for (int i = 1; i < n; i++) {
		if (nums[i] == 1) {
			dp0[i] = dp0[i - 1] + 1;
			dp1[i] = dp1[i - 1];
		}
		else {
			dp0[i] = dp1[i - 1];		//��ǰ��-1���˻�Ϊ���ĸ���ֻȡ����֮ǰ�Ǹ��ĸ���
			dp1[i] = dp0[i - 1] + 1;	//��Ϊ��ǰ��-1��֮ǰΪ�����ٳ�-1�϶�Ϊ����ͬʱ-1����Ҳ�Ǹ�
		}
	}
	int count = 0;
	for (int it : dp0) {
		count += it;
	}
	cout << count << endl;
}
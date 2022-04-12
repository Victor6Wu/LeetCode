//Ͱ���򣬸��ݸ��������е������Сֵ�Ĳ�ֵ����Ͱ��Ͱ�ĳߴ�����ó�1
//������Ͱ����Ͱ��Ԫ�����������
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(vector<int>& nums) {
	if (nums.empty()) return;
	int maxNum = *max_element(nums.begin(), nums.end());
	int minNum = *min_element(nums.begin(), nums.end());
	int n = maxNum - minNum + 1;
	vector<int> bucket(n, 0);		//Ͱ
	for (const int num : nums) {	//��Ԫ��װ��Ͱ��ʵ��Ͱ�ڱ�ʾ����ĳ�������ֵĴ���
		bucket[num - minNum]++;
	}
	//��ΪͰ�ĳߴ���1������Ҫ��Ͱ�ڽ����������ߴ����һ������ҪͰ��������
	int index = 0;
	for (int i = 0; i < n; i++) {		//����Ͱ
		for (int j = 1; j <= bucket[i]; j++) {
			nums[index++] = i + minNum;
		}
	}
}
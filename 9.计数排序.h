//�������򣬱�������һ�������Ͱ���򣬵�Ͱ�ĸ�������ʱ����Ǽ�������
#include<vector>
#include<algorithm>
using namespace std;

//����д����8.Ͱ����ӽ���ֻ��Ͱ�����ֵ������� Ԫ�س��ֵĴ��� �� Ԫ�س��ֵ����λ�ã�׼ȷ��˵�����λ�õĺ�һλ��
//���˸о�8.��д�������Ǽ�������
void CountSort(vector<int>& nums) {
	if(nums.empty()) return;
	int minNum = *min_element(nums.begin(), nums.end());
	int maxNum = *max_element(nums.begin(), nums.end());
	int n = maxNum - minNum + 1;
	vector<int> vecCount(n, 0);
	//ͳ�Ƴ��ִ���
	for (const int num : nums) {
		vecCount[num - minNum]++;
	}
	//��ǰ����ۼӳ��ֵĴ��������ڱ�ʾ����
	for (int i = 1; i < n; i++) {
		vecCount[i] += vecCount[i - 1];
	}
	//��������nums���б��������������Ϊ�˱�֤�ȶ���
	vector<int> tmp(nums.size(), 0);
	for (int i = nums.size() - 1; i >= 0; i--) {
		int tmp_index = vecCount[nums[i] - minNum] - 1;	//��ȡnums[i]Ӧ�ô�ŵ�λ��
		tmp[tmp_index] = nums[i];
		vecCount[nums[i] - minNum]--;		//�������λ��
	}
	swap(nums, tmp);
}
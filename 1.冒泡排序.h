//ԭ�������ȶ�
#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int>& nums, int n) {
	if (n < 1) return;
	//����һ����־����¼ѭ�����Ƿ������swap�����û�о���ǰ�˳�ѭ��
	bool is_swap = false;
	for (int i = 0; i < n - 1; i++) {		//ѭ��n - 1�˼���
		is_swap = false;
		for (int j = 1; j < n - i; j++) {	//�Ѿ������ס���Ԫ���������Ƚ�
			if (nums[j - 1] > nums[j]) {
				swap(nums[j - 1], nums[j]);
				is_swap = true;
			}
		}
		if (!is_swap) return;
	}
	return;
}

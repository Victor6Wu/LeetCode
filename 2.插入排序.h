//ԭ�������ȶ�
#include<vector>
using namespace std;

//�����鿼�ǳ� ������+������ �����֣��ڴ������б���ÿ��Ԫ��ȥ��ǰ��������ıȽϣ��ر�ע���ǴӺ���ǰ�Ƚϣ��Ӵ�С��
void InsertSort(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) return;
	for (int i = 1; i < n; i++) {			//����δ���򲿷�
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {		//�����������Ǳ�ǰ���С�����ڵ���������ں��棬�������Ա�֤�ȶ�����
			swap(nums[j], nums[j - 1]);
		}
	}
	return;
}
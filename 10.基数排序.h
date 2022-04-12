//��������һ�ֶ�ؼ��ֵ������㷨��
//�������ȼ������Ĵ������ÿ���ֶ���һ��Ͱ����
//���������ݿ��Էָ�������ġ�λ�����бȽϣ����ҡ�λ��֮���еݽ���ϵ������a�ĸ�λ��b�Ĵ���ô��λ�Ͳ��ñȽ���
#include<vector>
using namespace std;

//�Զ������������������Ϊ��
//Ҫ��һ���������ڻ�ȡָ��λ����ֵ����λͰ�����ʱ����9.��������ķ�����Ͱ�ڼ�¼ÿ���������ֵ�λ�ã�����Ͱ�͵��ö�ά������
int getBit(int num, int bit) {	//bit��ʾλ��
	int ans;
	while (bit > 0) {
		ans = num % 10;
		num /= 10;
		bit--;
	}
	return ans;
}

void radixSort(vector<int>& nums, int bit_count) {	//bit_count��ʾ�Ƚϵ�λ���ж��ٸ��������ǱȽϵĲ㼶����
	for (int bit = 1; bit <= bit_count; bit++) {	//�Ƚϵ�λ����1��ʼ�����ڱ����Ӿ��ǴӸ�λ��ʼ
		vector<int> bucket(10, 0);		//ÿ��λ����10��Ͱ�����ڴ�Ÿ�λ��ֵΪ0-9�������������9.�ķ����������άͰ
		for (const int num : nums) {
			bucket[getBit(num, bit)]++;
		}
		//��Ͱ������ۼӣ��޸ĳɴ洢�����λ��
		for (int i = 1; i < bucket.size(); i++) bucket[i] += bucket[i - 1];

		//����Ͱ����Ľ������
		vector<int> tmp(nums.size(), 0);		//tmp���ڱ�����һ������Ľ��
		for (int i = nums.size() - 1; i >= 0; i--) {
			tmp[bucket[getBit(nums[i], bit)] - 1] = nums[i];
			bucket[getBit(nums[i], bit)]--;		//�������һλ��λ��
		}
		//��ΪͰ�Ǿֲ�������һ��ѭ�������������ˣ����Ҫ�ٴ���nums
		swap(nums, tmp);
	}
}
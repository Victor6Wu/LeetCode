//�ѽ���һ����ȫ��������������һ������ʵ��
//��������Ҫ�������������ųɶ�
#include<vector>
using namespace std;

//���ô���ѣ����Ѷ�Ԫ�غ����һλ�������൱�ڣ�1.���ֵ���������2.�൱��ɾ���˶Ѷ�����ĩβ��Ԫ����ʱ�䵱�Ѷ�������һ�����ǲ������ɻָ�
//�����Ҫ�����������鹹���ɶѡ���Ҫ�����Ǹ��ڵ�Ĳ���

//1.�ڵ����ǣ���ǰ��i�����ȡ�������ҵ����ֵ�����������heapfiy��
void heapify(vector<int>& nums, int n, int i) {		//n��ʾ���鳤�ȣ�i��ʾҪ�������ǵĽڵ�����
	int left = i * 2 + 1, right = i * 2 + 2;		//������Һ��ӵ�����
	int max = i;									//�赱ǰ�ڵ�Ϊ���
	//�����Һ��ӽ��бȽ�
	if (left < n && nums[left] > nums[max]) {
		max = left;
	}
	if (right < n && nums[right] > nums[max]) {
		max = right;
	}
	//���max�����ı䣬��Ҫ���н��������Ҽ�������
	if (max != i) {
		swap(nums[max], nums[i]);
		heapify(nums, n, max);
	}
}

//2.�ø��������飬ԭ�ع�����
//��������ѣ������ĵ����ڶ����һ����㿪ʼ��
//��ÿ��������heapify������Ȼ�������ߣ�������һ�������
void heapify_build(vector<int>& nums, int n) {
	int tmp = (n - 2) / 2;			//�Ͱ�����������⣬���һ���ڵ��������n - 1����ô�丸�ڵ���(n - 1 - 1) / 2
	for (int i = tmp; i >= 0; i--) {
		heapify(nums, n, i);
	}
}

//3.������
void heapSort(vector<int>& nums) {
	int n = nums.size();
	heapify_build(nums, n);		//������
	for (int i = n - 1; i > 0; i--) {		//���ν��Ѷ�nums[0]������ĩβ���ѵ�ĩβ��Χ����С
		swap(nums[0], nums[i]);
		heapify(nums, i, 0);				//���µĶѶ��������ǲ���������ע�⣬�����鲻���Ǹոյ�ĩβ
	}
}
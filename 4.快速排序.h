//���ŵ�˼����ǣ�
//ȡ������Χ�ڵĵ�һ��Ԫ����Ϊpivot�㣬����pivotС�ĵ㽻������ǰ�棬����pivot�ĵ㽻��������
//���pivot����ͷ����ں��ʵ�λ���ˣ�����ǰ�������ֽ��еݹ鴦��
#include<vector>
using namespace std;

//�����бȽ��ѵĵط�������ô����pivotС�ķ���ǰ�棬��ķ��ں���
//���ôӺ���ǰ����+��ǰ�������ķ���
void QuickSort(vector<int>& nums, int low, int high) {		//low��high��������ұ�
	if (low >= high) return;
	int first = low, last = high;		//first��last���ڽ��������ܸı�low��high����Ϊ����ݹ黹Ҫ��
	int pivot = nums[first];			//ÿ�ζ���ȡ��һ��Ԫ����Ϊpivot
	while (first < last) {
		//�ȴӺ���ǰ�ҵ���һ����pivotС��Ԫ��
		while (first < last && nums[last] >= pivot) last--;
		if (first < last) nums[first] = nums[last];	//nums[first++] = nums[last] Ҳ����

		//��ǰ����ҵ���һ�����ڵ���pivot��Ԫ��
		while (first < last && nums[first] <= pivot) first++;
		if (first < last) nums[last] = nums[first];	//nums[last--] = nums[first] Ҳ����
	}
	//���first����pivotӦ�����ڵ�λ��
	nums[first] = pivot;

	QuickSort(nums, low, first - 1);
	QuickSort(nums, first + 1, high);
}
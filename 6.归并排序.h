//�ݹ�����ʱ�临�Ӷ�ʼ����O(NlogN)���ȶ�����ԭ��
//���������֣�1.�����鿼�ǳ������֣��������ֱַ����򣬶�Ӧ�ݹ鲿��
//2.��������ɵ������ֽ��кϲ�����һ�����൱���ǰ�˳��ϲ���������Ĳ���
#include<vector>
#include<algorithm>
using namespace std;

//�ݹ鷨1:
//2.��˳��ϲ�����������֣����������Ҫ����һ����ʱ����;�����а����м�㣬��[L, mid]��[mid+1��R]��������
void mergeVec(vector<int>& nums, int L, int mid, int R) {
	vector<int> tmp(R - L + 1);
	int i = L;
	int j = mid + 1;
	int k = 0;	//��¼��ʱ����tmp������
	//ѭ���Ƚ��������ֵ�Ԫ�أ���С�ķ���
	while (i <= mid && j <= R) {
		if (nums[i] < nums[j]) {
			tmp[k++] = nums[i++];
		}
		else {
			tmp[k++] = nums[j++];
		}
	}
	//����Ƿ���һ�����ֻ���Ԫ��û�����������о�ֱ�ӽ��ں��漴��
	while (i <= mid) {
		tmp[k++] = nums[i++];
	}
	while (j <= R) {
		tmp[k++] = nums[j++];
	}
	//��tmp�е�Ԫ���ٷŻ�nums
	for (int p = 0; p < k; p++) {
		nums[L + p] = tmp[p];
	}
}

//1.�ݹ鷽ʽ���ֱ����������֣��ٺϲ���������������ҷ�Χ
void MergeSort1(vector<int>& nums, int L, int R) {
	if (L >= R) return;
	int mid = L + (R - L) / 2;
	MergeSort1(nums, L, mid);
	MergeSort1(nums, mid + 1, R);
	mergeVec(nums, L, mid, R);
}


//�ݹ鷨2����һ��ʼ�ʹ���һ����ʱ���飬��õݹ��ʱ�򷴸�������ʱ����
void mergeSortCore(vector<int>& nums, vector<int>& tmp, int L, int R) {
	if (L >= R) return;
	int mid = L + (R - L) / 2;
	mergeSortCore(nums, tmp, L, mid);
	mergeSortCore(nums, tmp, mid + 1, R);
	int i = L, j = mid + 1, k = L;		//k��������¼����ʱ�����д洢��λ��
	while (i <= mid && j <= R) {
		if (nums[i] < nums[j]) {
			tmp[k++] = nums[i++];
		}
		else {
			tmp[k++] = nums[j++];
		}
	}
	while (i <= mid) {
		tmp[k++] = nums[i++];
	}
	while (j <= R) {
		tmp[k++] = nums[j++];
	}

	//�Ż�nums���飬����ע���뷽��1������k������Ǿ��������λ���ˣ����ǳ���
	for (int p = L; p < k; p++) {
		nums[p] = tmp[p];
	}
}

void mergeSort2(vector<int>& nums) {
	vector<int> tmp(nums.size(), 0);		//����һ����ʱ����ռ䣬���ںϲ��������򲿷�
	mergeSortCore(nums, tmp, 0, nums.size() - 1);
}

//���������ؼ���Ҫ������鲢�������ֵ�����
void mergeSort3(vector<int>& nums) {
	int n = nums.size();
	vector<int> tmp(nums.size());
	//���Թ鲢��Ƭ����СΪ1��ÿ�η��������ᳬ��nums.size()
	for (int seg = 1; seg < n; seg += seg) {
		//ÿ����Ƭ�ν��й鲢������һ�飬��ô����Ӧ����2*seg
		for (int start = 0; start < n; start += 2 * seg) {
			//ȷ����Ҫ�鲢�������ֵ���ֹ����(����ҿ�)��������ĩβ���Ȳ���������midӦ����+seg��high��+2*seg
			int low = start, mid = min(low + seg, n), high = min(low + 2 * seg, n);
			int i = low, j = mid, index = low;		//index��ʾtmp��ʼ�洢������
			while (i < mid && j < high) {
				tmp[index++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
			}
			while (i < mid) {
				tmp[index++] = nums[i++];
			}
			while (j < high) {
				tmp[index++] = nums[j++];
			}
		}
		//���ϣ��������鰴�շ������ʽ�����ڵ�����seg�����˹鲢��Ȼ���ٷŻ�ԭ����
		swap(nums, tmp);
	}
}

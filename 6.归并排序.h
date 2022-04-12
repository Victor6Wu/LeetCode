//递归排序，时间复杂度始终是O(NlogN)，稳定，非原地
//包含两部分：1.将数组考虑成两部分，对两部分分别排序，对应递归部分
//2.将排序完成的两部分进行合并，这一部分相当于是按顺序合并两个数组的操作
#include<vector>
#include<algorithm>
using namespace std;

//递归法1:
//2.按顺序合并数组的两部分，这个过程需要借助一个临时数组;参数中包括中间点，即[L, mid]，[mid+1，R]两个区间
void mergeVec(vector<int>& nums, int L, int mid, int R) {
	vector<int> tmp(R - L + 1);
	int i = L;
	int j = mid + 1;
	int k = 0;	//记录临时数组tmp的索引
	//循环比较两个部分的元素，将小的放入
	while (i <= mid && j <= R) {
		if (nums[i] < nums[j]) {
			tmp[k++] = nums[i++];
		}
		else {
			tmp[k++] = nums[j++];
		}
	}
	//检查是否有一个部分还有元素没参与排序，若有就直接接在后面即可
	while (i <= mid) {
		tmp[k++] = nums[i++];
	}
	while (j <= R) {
		tmp[k++] = nums[j++];
	}
	//将tmp中的元素再放回nums
	for (int p = 0; p < k; p++) {
		nums[L + p] = tmp[p];
	}
}

//1.递归方式，分别排序两部分，再合并；给定数组的左右范围
void MergeSort1(vector<int>& nums, int L, int R) {
	if (L >= R) return;
	int mid = L + (R - L) / 2;
	MergeSort1(nums, L, mid);
	MergeSort1(nums, mid + 1, R);
	mergeVec(nums, L, mid, R);
}


//递归法2：在一开始就创建一个临时数组，免得递归的时候反复构造临时数组
void mergeSortCore(vector<int>& nums, vector<int>& tmp, int L, int R) {
	if (L >= R) return;
	int mid = L + (R - L) / 2;
	mergeSortCore(nums, tmp, L, mid);
	mergeSortCore(nums, tmp, mid + 1, R);
	int i = L, j = mid + 1, k = L;		//k是用来记录在临时数组中存储的位置
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

	//放回nums数组，这里注意与方法1的区别，k代表的是具体的索引位置了，不是长度
	for (int p = L; p < k; p++) {
		nums[p] = tmp[p];
	}
}

void mergeSort2(vector<int>& nums) {
	vector<int> tmp(nums.size(), 0);		//创建一个临时数组空间，用于合并两个排序部分
	mergeSortCore(nums, tmp, 0, nums.size() - 1);
}

//迭代法：关键是要捋清楚归并的两部分的索引
void mergeSort3(vector<int>& nums) {
	int n = nums.size();
	vector<int> tmp(nums.size());
	//可以归并的片段最小为1，每次翻倍，不会超过nums.size()
	for (int seg = 1; seg < n; seg += seg) {
		//每两个片段进行归并，看做一组，那么组间距应该是2*seg
		for (int start = 0; start < n; start += 2 * seg) {
			//确定需要归并的两部分的起止索引(左闭右开)，不考虑末尾长度不足的情况，mid应该是+seg，high是+2*seg
			int low = start, mid = min(low + seg, n), high = min(low + 2 * seg, n);
			int i = low, j = mid, index = low;		//index表示tmp开始存储的索引
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
		//以上，整个数组按照分组的形式对组内的两个seg进行了归并，然后再放回原数组
		swap(nums, tmp);
	}
}

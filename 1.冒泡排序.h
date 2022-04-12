//原地排序，稳定
#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int>& nums, int n) {
	if (n < 1) return;
	//设置一个标志，记录循环中是否进行了swap，如果没有就提前退出循环
	bool is_swap = false;
	for (int i = 0; i < n - 1; i++) {		//循环n - 1趟即可
		is_swap = false;
		for (int j = 1; j < n - i; j++) {	//已经“沉底”的元素无需参与比较
			if (nums[j - 1] > nums[j]) {
				swap(nums[j - 1], nums[j]);
				is_swap = true;
			}
		}
		if (!is_swap) return;
	}
	return;
}

//原地排序，稳定
#include<vector>
using namespace std;

//将数组考虑成 已排序+待排序 两部分，在待排序中遍历每个元素去和前面已排序的比较，特别注意是从后向前比较（从大到小）
void InsertSort(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) return;
	for (int i = 1; i < n; i++) {			//遍历未排序部分
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {		//交换的条件是比前面的小，等于的情况就排在后面，这样可以保证稳定排序
			swap(nums[j], nums[j - 1]);
		}
	}
	return;
}
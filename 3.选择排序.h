//原地排序，不稳定
//选择排序，和插入排序的思路相似，将数组考虑成 已排序+待排序 两部分
//不同点在于：插入排序是将待排元素往已排序部分插入的时候，有一个从后向前循环的过程；选择排序是在待排序中循环找到最小的元素，挑出来直接方到已排序部分的尾部
#include<vector>
using namespace std;

void SelectSort(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) return;
	//外层循环逐步缩小待排序元素的范围
	for (int i = 0; i < n - 1; i++) {			//待排序部分只有1个元素的时候就没必要选择排序了
		int mid = i;
		for (int j = i + 1; j < n; j++) {		//找到最小的元素
			if (nums[mid] > nums[j]) {
				mid = j;
			}
		}
		swap(nums[mid], nums[i]);				//交换未排序部分中的 最小元素 和 未排序的首元素
	}
}
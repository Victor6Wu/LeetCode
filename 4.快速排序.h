//快排的思想就是：
//取给定范围内的第一个元素作为pivot点，将比pivot小的点交换到其前面，大于pivot的点交换到后面
//最后pivot本身就放置在合适的位置了，对其前后两部分进行递归处理
#include<vector>
using namespace std;

//快排中比较难的地方在于怎么将比pivot小的放在前面，大的放在后面
//采用从后向前遍历+从前向后遍历的方法
void QuickSort(vector<int>& nums, int low, int high) {		//low和high采用左闭右闭
	if (low >= high) return;
	int first = low, last = high;		//first和last用于交换，不能改变low和high，因为后面递归还要用
	int pivot = nums[first];			//每次都是取第一个元素作为pivot
	while (first < last) {
		//先从后向前找到第一个比pivot小的元素
		while (first < last && nums[last] >= pivot) last--;
		if (first < last) nums[first] = nums[last];	//nums[first++] = nums[last] 也可以

		//从前向后找到第一个大于等于pivot的元素
		while (first < last && nums[first] <= pivot) first++;
		if (first < last) nums[last] = nums[first];	//nums[last--] = nums[first] 也可以
	}
	//最后first就是pivot应该属于的位置
	nums[first] = pivot;

	QuickSort(nums, low, first - 1);
	QuickSort(nums, first + 1, high);
}
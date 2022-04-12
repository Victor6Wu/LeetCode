//希尔排序的基本思想是插入排序，只是多了一层思考：
//原数组的一个元素如果距离它正确的位置很远的话，则需要与相邻元素交换很多次才能到达正确的位置，这样是相对比较花时间了
//希尔排序的思想是采用插入排序的方法，先让数组中任意间隔为 h 的元素有序,刚开始 h 的大小可以是 h = n / 2,接着让 h = n / 4，让 h 一直缩小
#include<vector>
using namespace std;

//希尔排序的难点在于怎么实现分组的插入排序
void ShellSort(vector<int>& nums) {
	int n = nums.size();
	for (int gap = n / 2; gap > 0; gap /= 2) {		//gap从一半的nums.size倍减至1
		//剩余的代码对分组进行插入排序
		for (int i = gap; i < n; i++) {				//按照插入排序的思想，应该从组中第二个元素开始向前插入排序；这里不需要再对分组分别写循环进行插入排序，i++即可
			for (int j = i; j - gap >= 0 && nums[j] < nums[j - gap]; j -= gap) {	//这层循环与插入排序基本一样，只是j每次前进gap的长度
				swap(nums[j], nums[j - gap]);
			}
		}
	}
}
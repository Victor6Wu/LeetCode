//堆近似一个完全二叉树，可以用一个数组实现
//堆排序，先要将给定的数组排成堆
#include<vector>
using namespace std;

//采用大根堆，将堆顶元素和最后一位交换，相当于：1.最大值放在了最后；2.相当于删除了堆顶，用末尾的元素暂时充当堆顶，进行一遍下虑操作即可恢复
//因此需要将给定的数组构建成堆、需要有下虑根节点的操作

//1.节点下虑，当前第i个结点取根，左右的最大值（这个操作称heapfiy）
void heapify(vector<int>& nums, int n, int i) {		//n表示数组长度，i表示要进行下虑的节点索引
	int left = i * 2 + 1, right = i * 2 + 2;		//获得左右孩子的索引
	int max = i;									//设当前节点为最大
	//与左右孩子进行比较
	if (left < n && nums[left] > nums[max]) {
		max = left;
	}
	if (right < n && nums[right] > nums[max]) {
		max = right;
	}
	//如果max发生改变，需要进行交换，并且继续下虑
	if (max != i) {
		swap(nums[max], nums[i]);
		heapify(nums, n, max);
	}
}

//2.用给定的数组，原地构建堆
//建立大根堆，从树的倒数第二层第一个结点开始，
//对每个结点进行heapify操作，然后向上走，最后就是一个大根堆
void heapify_build(vector<int>& nums, int n) {
	int tmp = (n - 2) / 2;			//就按照左孩子来理解，最后一个节点的索引是n - 1，那么其父节点是(n - 1 - 1) / 2
	for (int i = tmp; i >= 0; i--) {
		heapify(nums, n, i);
	}
}

//3.堆排序
void heapSort(vector<int>& nums) {
	int n = nums.size();
	heapify_build(nums, n);		//建立堆
	for (int i = n - 1; i > 0; i--) {		//依次将堆顶nums[0]交换至末尾，堆的末尾范围逐渐缩小
		swap(nums[0], nums[i]);
		heapify(nums, i, 0);				//对新的堆顶进行下虑操作，这里注意，新数组不考虑刚刚的末尾
	}
}
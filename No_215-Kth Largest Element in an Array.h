//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	//solution :借用sort函数
	int findKthLargest1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}

	//solution 1:自写快排
	void quickSort1(vector<int>& nums, int lo, int hi) {			//快排的递归程序
		if (hi <= lo) return;
		int j = partition1(nums, lo, hi);
		quickSort1(nums, lo, j - 1);
		quickSort1(nums, j + 1, hi);
	 }
	//数组切分
	int partition1(vector<int>& nums, int lo, int hi) {
		int left = lo, right = hi;		//左指针从lo开始，右指针从hi开始
		int element = nums[lo];
		while (left < right) {
			while (nums[left] <= element) {		//此处采用 <= ，所以left可以从lo开始
				if (left == hi) break;
				left++;
			}
			while (nums[right] > element) {
				if (right == lo) break;
				right--;
			}
			//判断左右指针是否相遇
			if (left >= right) {
				break;
			}
			swap(nums[left], nums[right]);		//在还没相遇前，交换左右指针所指元素
		}
		//左右指针相遇后，将element放在合适的位置
		swap(nums[lo], nums[right]);	//注意这里是与right交换，因为根据前面的操作，right所指的元素是 <= element 的
		return right;
	}

	int findKthLargest1(vector<int>& nums, int k) {
		quickSort1(nums, 0, nums.size() - 1);
		return nums[nums.size() - k];
	}

	//solution 2:快排改进，根据题目要求第K大，中途找到即可退出
	void quickSort2(vector<int>& nums, int lo, int hi, int k) {			//快排的递归程序
		if (hi <= lo) return ;
		int j = partition2(nums, lo, hi);
		if (j != nums.size() - k) {
			quickSort2(nums, lo, j - 1, k);
			quickSort2(nums, j + 1, hi, k);
		}
		else return;
	}
	//数组切分
	int partition2(vector<int>& nums, int lo, int hi) {
		int left = lo, right = hi;		//左指针从lo开始，右指针从hi开始
		int element = nums[lo];
		while (left < right) {
			while (nums[left] <= element) {		//此处采用 <= ，所以left可以从lo开始
				if (left == hi) break;
				left++;
			}
			while (nums[right] > element) {
				if (right == lo) break;
				right--;
			}
			//判断左右指针是否相遇
			if (left >= right) {
				break;
			}
			swap(nums[left], nums[right]);		//在还没相遇前，交换左右指针所指元素
		}
		//左右指针相遇后，将element放在合适的位置
		swap(nums[lo], nums[right]);	//注意这里是与right交换，因为根据前面的操作，right所指的元素是 <= element 的
		return right;
	}

	int findKthLargest2(vector<int>& nums, int k) {
		quickSort2(nums, 0, nums.size() - 1, k);
		return nums[nums.size() - k];
	}

	//solution 3:基于堆，大根堆，连续K次删除根节点，可以直接用priority_queue，也要会自己写	
	int findKthLargest3(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, less<int>> q;
		for (const auto& x : nums) {
			q.push(x);
		}
		for (int i = 1; i < k; i++) {
			q.pop();
		}
		return q.top();
	}

	//solution 4:基于小根堆，控制堆的规模始终为K
	int findKthLargest4(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < k; i++) {
			q.push(nums[i]);
		}
		for (int i = k; i < nums.size(); i++) {
			if (nums[i] > q.top()) {
				q.pop();
				q.push(nums[i]);
			}
		}
		return q.top();
	}
};
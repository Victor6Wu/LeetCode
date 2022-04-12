//基数排序，一种多关键字的排序算法、
//按照优先级递增的次序，针对每个字段做一趟桶排序
//适用于数据可以分割出独立的“位”进行比较，并且“位”之间有递进关系，比如a的高位比b的大，那么低位就不用比较了
#include<vector>
using namespace std;

//以对正整数数组进行排序为例
//要有一个函数用于获取指定位的数值；按位桶排序的时候按照9.计数排序的方法，桶内记录每个数最后出现的位置，否则桶就得用二维数组了
int getBit(int num, int bit) {	//bit表示位数
	int ans;
	while (bit > 0) {
		ans = num % 10;
		num /= 10;
		bit--;
	}
	return ans;
}

void radixSort(vector<int>& nums, int bit_count) {	//bit_count表示比较的位数有多少个，或者是比较的层级个数
	for (int bit = 1; bit <= bit_count; bit++) {	//比较的位数从1开始，对于本例子就是从个位开始
		vector<int> bucket(10, 0);		//每个位都有10个桶，用于存放该位数值为0-9的数，这里采用9.的方法，避免二维桶
		for (const int num : nums) {
			bucket[getBit(num, bit)]++;
		}
		//将桶里的数累加，修改成存储的最后位置
		for (int i = 1; i < bucket.size(); i++) bucket[i] += bucket[i - 1];

		//倒序将桶排序的结果保存
		vector<int> tmp(nums.size(), 0);		//tmp用于保存这一次排序的结果
		for (int i = nums.size() - 1; i >= 0; i--) {
			tmp[bucket[getBit(nums[i], bit)] - 1] = nums[i];
			bucket[getBit(nums[i], bit)]--;		//更新最后一位的位置
		}
		//因为桶是局部变量，一次循环结束就析构了，因此要再传回nums
		swap(nums, tmp);
	}
}
//计数排序，本质上是一种特殊的桶排序，当桶的个数最大的时候就是计数排序
#include<vector>
#include<algorithm>
using namespace std;

//主体写法和8.桶排序接近，只是桶内数字的意义由 元素出现的次数 → 元素出现的最后位置（准确来说是最后位置的后一位）
//个人感觉8.的写法更像是计数排序
void CountSort(vector<int>& nums) {
	if(nums.empty()) return;
	int minNum = *min_element(nums.begin(), nums.end());
	int maxNum = *max_element(nums.begin(), nums.end());
	int n = maxNum - minNum + 1;
	vector<int> vecCount(n, 0);
	//统计出现次数
	for (const int num : nums) {
		vecCount[num - minNum]++;
	}
	//从前向后累加出现的次数，用于表示索引
	for (int i = 1; i < n; i++) {
		vecCount[i] += vecCount[i - 1];
	}
	//这里必须对nums进行遍历；倒序遍历是为了保证稳定性
	vector<int> tmp(nums.size(), 0);
	for (int i = nums.size() - 1; i >= 0; i--) {
		int tmp_index = vecCount[nums[i] - minNum] - 1;	//获取nums[i]应该存放的位置
		tmp[tmp_index] = nums[i];
		vecCount[nums[i] - minNum]--;		//更新最后位置
	}
	swap(nums, tmp);
}
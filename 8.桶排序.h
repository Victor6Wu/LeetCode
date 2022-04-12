//桶排序，根据给定数组中的最大最小值的差值设置桶，桶的尺寸就设置成1
//最后遍历桶，将桶内元素重填到数组中
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(vector<int>& nums) {
	if (nums.empty()) return;
	int maxNum = *max_element(nums.begin(), nums.end());
	int minNum = *min_element(nums.begin(), nums.end());
	int n = maxNum - minNum + 1;
	vector<int> bucket(n, 0);		//桶
	for (const int num : nums) {	//将元素装入桶，实际桶内表示的是某个数出现的次数
		bucket[num - minNum]++;
	}
	//因为桶的尺寸是1，不需要对桶内进行排序；若尺寸大于一，就需要桶内排序了
	int index = 0;
	for (int i = 0; i < n; i++) {		//遍历桶
		for (int j = 1; j <= bucket[i]; j++) {
			nums[index++] = i + minNum;
		}
	}
}
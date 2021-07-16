//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
//If the array contains less than two elements, return 0.
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1 :用sort排序
	int maximumGap1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0;
		int n = nums.size();
		if (n < 2) {
			return ans;
		}
		else {
			for (int i = 1; i < n; i++) {
				int temp = nums[i] - nums[i - 1];
				ans = max(ans, temp);
			}
		}
		return ans;
	}

	//solution 2:基数排序，时间复杂度O(N),空间复杂度O(N)，利用个位、十位、...依次进行分桶，重装数组
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return 0;
		}
		int divisor = 1;		//除数从1开始，10、1000......
		vector<int> buf(n);		//用于盛放重组数组
		int maxVal = *max_element(nums.begin(), nums.end());
		while (maxVal >= divisor) {			//除数不能超过最大的数，否则没有意义
			vector<int> count(10);			//用于统计当前位为0-9的桶内数字的个数

			//统计各桶内数字个数
			for (int i = 0; i < n; i++) {
				int digit = (nums[i] / divisor) % 10;		//得到当前位的数字
				count[digit]++;
			}

			//很重要的一步：将cout内从前到后逐次累加，这关系到后面对数组重组
			for (int i = 1; i < 10; i++) {
				count[i] += count[i - 1];
			}

			//利用cout数组对桶内的数字进行重组，从后向前进行，否则会影响之前已经排好的顺序
			for (int i = n - 1; i >= 0; i--) {
				int digit = (nums[i] / divisor) % 10;
				buf[count[digit] - 1] = nums[i];		//count[digit] - 1确定当前数在重组数组中的索引
				count[digit]--;
			}

			copy(buf.begin(), buf.end(), nums.begin());		//在个、十、百...位上大小有序，覆盖原始数组
			divisor *= 10;
		}

		//判断最大Gap
		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans = max(ans, nums[i] - nums[i - 1]);
		}
		return ans;
	}
};
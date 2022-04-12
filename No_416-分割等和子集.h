//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

//动态规划方法1，二维数组
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {		//如果只有一个元素，肯定不能划分出
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxNum = *max_element(nums.begin(), nums.end());		//获取最大元素
		//sum为奇数返回false；sum/2<maxNum则返回false
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		if (maxNum > target) return false;
		vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
		//初始化边界条件
		for (int i = 0; i < n; i++) {
			dp[i][0] = true;	//第一列均为true
		}
		dp[0][nums[0]] = true;	//第一行中只有刚好等于nums[0]的位置为true
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= target; j++) {
				if (j >= nums[i]) {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n - 1][target];
	}
};

//动态规划方法1，一维数组
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {		//如果只有一个元素，肯定不能划分出
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxNum = *max_element(nums.begin(), nums.end());		//获取最大元素
		//sum为奇数返回false；sum/2<maxNum则返回false
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		if (maxNum > target) return false;
		vector<bool> dp(target + 1, false);
		//初始化边界条件
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = target; j >= nums[i]; j--) {		//从大到小遍历，并且终止到不满足容量的时候，因为容量不够的部分相当于维持原有dp[j]
				dp[j] = dp[j] || dp[j - nums[i]];
			}
		}
		return dp[target];
	}
};

//动态规划方法2，代码随想录，还是考虑价值，只不过这题物品的价值就是物品的重量，那么每个dp[j]就取最大价值即可，因为dp[j]的最大值不会超过j
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {		//如果只有一个元素，肯定不能划分出
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxNum = *max_element(nums.begin(), nums.end());		//获取最大元素
		//sum为奇数返回false；sum/2<maxNum则返回false
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		if (maxNum > target) return false;
		//如果题目给的价值都是正整数那么非0下标都初始化为0就可以了，如果题目给的价值有负数，那么非0下标就要初始化为负无穷。
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = target; j >= nums[i]; j--) {		//从大到小遍历，并且终止到不满足容量的时候，因为容量不够的部分相当于维持原有dp[j]
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);			//与方法1唯一不同的就是dp的含义，也仅仅体现在此处
			}
		}
		//最后判断一下dp[target]能获得的最大价值是不是刚刚是target
		return dp[target] == target ? true : false;
	}
};
//有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
//每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

//借鉴No_416题的思想，本题可以转成：将数组分成两部分，使得两部分的差值最小
//换言之，将总和的一半作为背包重量，从中挑出元素使得背包尽可能满
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
		int n = stones.size();
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int target = sum / 2;	//总和的平均值作为背包重量，向下取整
		vector<int> dp(target + 1, 0);
		//dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背dp[j]这么重的石头。
		for (int i = 0; i < n; i++) {
			for (int j = target; j >= stones[i]; j--) {		//从大到小遍历，并且终止到不满足容量的时候，因为容量不够的部分相当于维持原有dp[j]
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);			//与方法1唯一不同的就是dp的含义，也仅仅体现在此处
			}
		}

		return (sum - dp[target]) - dp[target];
    }
};
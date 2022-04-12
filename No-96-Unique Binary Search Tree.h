//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
#include"TreeNode.h";
#include<vector>
using namespace std;

//solution 1:递归法
class Solution {
public:
	int numTrees(int n) {
		if (n <= 1) return 1;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = ans + numTrees(i - 1) * numTrees(n - i);
		}
		return ans;
	}
};

//solution 2:动态规划法，思路可以从递归法理解，相较于sln1，sln2将中间相乘的那部分和两端的情况总结成统一的格式，利用动态规划的方法从1开始构建动态数组
class Solution {
public:
	int numTrees(int n) {
		vector<int> G(n + 1, 0);
		G[0] = 1;		//注意，这里空子树也算是一种结果，要初始化为1，不能设置为0
		G[1] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				G[i] += G[j - 1] * G[i - j];
			}
		}
		return G[n];
	}
};

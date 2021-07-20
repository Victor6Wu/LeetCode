//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
#include"TreeNode.h";
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:递归法
	int numTrees1(int n) {
		if (n <= 1) return n;
		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans = ans + numTrees1(i) * numTrees1(n - i - 1);
		}
		ans += 2 * numTrees1(n - 1);
		return ans;
	}

	//solution 2:动态规划法，思路可以从递归法理解，相较于sln1，sln2将中间相乘的那部分和两端的情况总结成统一的格式，利用动态规划的方法从1开始构建动态数组
	int numTrees2(int n) {
		vector<int> G(n + 1, 0);
		G[0] = 0;
		G[1] = 1;
		for (int i = 2; i <= 0; i++) {
			for (int j = 1; j <= i; j++) {
				G[i] += G[j - 1] * G[i - j];
			}
		}
		return G[n];
	}
};

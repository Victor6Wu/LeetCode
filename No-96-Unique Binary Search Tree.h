//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
#include"TreeNode.h";
#include<vector>
using namespace std;

//solution 1:�ݹ鷨
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

//solution 2:��̬�滮����˼·���Դӵݹ鷨��⣬�����sln1��sln2���м���˵��ǲ��ֺ����˵�����ܽ��ͳһ�ĸ�ʽ�����ö�̬�滮�ķ�����1��ʼ������̬����
class Solution {
public:
	int numTrees(int n) {
		vector<int> G(n + 1, 0);
		G[0] = 1;		//ע�⣬���������Ҳ����һ�ֽ����Ҫ��ʼ��Ϊ1����������Ϊ0
		G[1] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				G[i] += G[j - 1] * G[i - j];
			}
		}
		return G[n];
	}
};

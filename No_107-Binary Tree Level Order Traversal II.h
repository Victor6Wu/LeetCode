//Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
#include"TreeNode.h"
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	//广度优先搜索，直接reverse
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector <vector <int>> ret;
		if (!root) {
			return ret;
		}

		queue <TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int currentLevelSize = q.size();		//当前的size就是将要pop层的节点数
			ret.push_back(vector <int>());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				ret.back().push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			//循环结束后，一层的遍历就结束了，队列中剩下的是该层的子节点，即下一层的节点
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
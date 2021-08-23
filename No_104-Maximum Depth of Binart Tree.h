//Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
#include"TreeNode.h"
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:广度优先搜索，自编代码，根据前面No_102的结果，取size（）即可
	int maxDepth1(TreeNode* root) {
		vector <vector <int>> ret;
		if (!root) {
			return 0;
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
		return ret.size();
	}

	//solution 2:深度优先搜索,左右子树递归计算最大深度
	int maxDepth2(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
	}

	//solution 3:广度优先搜索
	int maxDepth3(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> Q;
		Q.push(root);
		int ans = 0;
		while (!Q.empty()) {
			int sz = Q.size();
			while (sz > 0) {
				TreeNode* node = Q.front(); Q.pop();
				if (node->left) Q.push(node->left);
				if (node->right) Q.push(node->right);
				sz -= 1;
			}
			ans += 1;
		}
		return ans;
	}
};
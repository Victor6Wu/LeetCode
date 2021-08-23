//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
#include"TreeNode.h"
#include<queue>
using namespace std;

class Solution {
public:
	//solution 1:自编代码，迭代的思想
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;
		q.push(root);
		int counterA = 1, counterB = 0;	//创建两个计数器，一个用于+，一个用于-
		while (!q.empty()) {
			vector<int> temp;
			while (counterA > 0) {
				root = q.front();
				q.pop();
				counterA--;
				if (root != nullptr) {
					temp.push_back(root->val);
					q.push(root->left);
					q.push(root->right);
					counterB = counterB + 2;
				}
			}
			if (!temp.empty()) ans.push_back(temp);
			//更新计数器
			counterA = counterB;
			counterB = 0;
		}
		return ans;
	}

	//代码优化，思路同自编类似，只是不需要两个计数器，只是每层pop()前先取出size
	vector<vector<int>> levelOrder(TreeNode* root) {
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
		return ret;
	}
};
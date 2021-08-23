//Given the root of a binary tree, ansurn the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
#include"TreeNode.h"
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:基于No_102,根据signal表示的方向，选择直接push(temp),还是先reverse
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector <vector <int>> ans;
		if (!root) {
			return ans;
		}

		queue <TreeNode*> q;
		q.push(root);
		bool signal = true;
		while (!q.empty()) {
			int currentLevelSize = q.size();		//当前的size就是将要pop层的节点数
			vector<int> temp;
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				temp.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			//循环结束后，一层的遍历就结束了，队列中剩下的是该层的子节点，即下一层的节点
			if (signal) {
				ans.push_back(temp);
			}
			else {
				reverse(temp.begin(), temp.end());
				ans.push_back(temp);
			}
			signal = !signal;
		}
		return ans;
    }
};
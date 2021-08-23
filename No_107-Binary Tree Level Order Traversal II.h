//Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
#include"TreeNode.h"
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	//�������������ֱ��reverse
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector <vector <int>> ret;
		if (!root) {
			return ret;
		}

		queue <TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int currentLevelSize = q.size();		//��ǰ��size���ǽ�Ҫpop��Ľڵ���
			ret.push_back(vector <int>());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				ret.back().push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			//ѭ��������һ��ı����ͽ����ˣ�������ʣ�µ��Ǹò���ӽڵ㣬����һ��Ľڵ�
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
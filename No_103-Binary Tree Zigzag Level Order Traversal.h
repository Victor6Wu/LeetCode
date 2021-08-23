//Given the root of a binary tree, ansurn the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
#include"TreeNode.h"
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:����No_102,����signal��ʾ�ķ���ѡ��ֱ��push(temp),������reverse
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector <vector <int>> ans;
		if (!root) {
			return ans;
		}

		queue <TreeNode*> q;
		q.push(root);
		bool signal = true;
		while (!q.empty()) {
			int currentLevelSize = q.size();		//��ǰ��size���ǽ�Ҫpop��Ľڵ���
			vector<int> temp;
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				temp.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			//ѭ��������һ��ı����ͽ����ˣ�������ʣ�µ��Ǹò���ӽڵ㣬����һ��Ľڵ�
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
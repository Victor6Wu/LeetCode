//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
#include"TreeNode.h"
#include<queue>
using namespace std;

class Solution {
public:
	//solution 1:�Ա���룬������˼��
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;
		q.push(root);
		int counterA = 1, counterB = 0;	//����������������һ������+��һ������-
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
			//���¼�����
			counterA = counterB;
			counterB = 0;
		}
		return ans;
	}

	//�����Ż���˼·ͬ�Ա����ƣ�ֻ�ǲ���Ҫ������������ֻ��ÿ��pop()ǰ��ȡ��size
	vector<vector<int>> levelOrder(TreeNode* root) {
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
		return ret;
	}
};
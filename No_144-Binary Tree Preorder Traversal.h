//Given the root of a binary tree, return the preorder traversal of its nodes' values.
#include"TreeNode.h"
#include<vector>
#include<stack>
using namespace std;

//solution1:�ݹ�
class Solution1 {
public:
	void preorder(vector<int>& res, TreeNode* root) {
		if (root == nullptr) return;
		res.push_back(root->val);
		preorder(res, root->left);
		preorder(res, root->right);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorder(res, root);
		return res;
	}
};

//solution2:������
class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* node = stk.top();
			stk.pop();
			if (node != nullptr) {
				res.push_back(node->val);
				stk.push(node->right);
				stk.push(node->left);
			}
		}
		return res;
	}
};

//solution3:morris��
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}

		TreeNode* p1 = root, * p2 = nullptr;

		while (p1 != nullptr) {
			p2 = p1->left;
			if (p2 != nullptr) {	//���뵱ǰ�ڵ��������
				//ѭ���ҵ������������ҽڵ�
				while (p2->right != nullptr && p2->right != p1) {
					p2 = p2->right;
				}
				//�жϵ�ǰ���������ҽڵ��Ƿ��Ѿ�����
				if (p2->right == nullptr) {
					res.emplace_back(p1->val);
					p2->right = p1;		//�νӽڵ�
					p1 = p1->left;
					continue;			//���continue����Ҫ��������һ��ѭ��������ִ��ʣ��Ĵ���
				}

				else {
					p2->right = nullptr;
				}
			}
			else {
				res.emplace_back(p1->val);
			}
			//����������
			p1 = p1->right;
		}
		return res;
	}
};
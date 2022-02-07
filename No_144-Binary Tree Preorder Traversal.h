//Given the root of a binary tree, return the preorder traversal of its nodes' values.
#include"TreeNode.h"
#include<vector>
#include<stack>
using namespace std;

//solution1:递归
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

//solution2:迭代法
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

//solution3:morris法
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
			if (p2 != nullptr) {	//进入当前节点的左子树
				//循环找到左子树的最右节点
				while (p2->right != nullptr && p2->right != p1) {
					p2 = p2->right;
				}
				//判断当前左子树最右节点是否已经连接
				if (p2->right == nullptr) {
					res.emplace_back(p1->val);
					p2->right = p1;		//衔接节点
					p1 = p1->left;
					continue;			//这个continue很重要，进入下一次循环，而不执行剩余的代码
				}

				else {
					p2->right = nullptr;
				}
			}
			else {
				res.emplace_back(p1->val);
			}
			//进入右子树
			p1 = p1->right;
		}
		return res;
	}
};
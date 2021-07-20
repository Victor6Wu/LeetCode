//Given the root of a binary tree, return the inorder traversal of its nodes' values.
#include"TreeNode.h"
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	//solution 1:递归法
	vector<int> inorderTraversal1(TreeNode* root) {
		if (root == nullptr) return {};
		vector<int> ans;
		specificinorderTraversal(root, ans);
		return ans;
	}

	void specificinorderTraversal(TreeNode* root, vector<int>& ans) {
		if (root->left != nullptr) {
			specificinorderTraversal(root->left, ans);
		}
		ans.push_back(root->val);
		if (root->right != nullptr) {
			specificinorderTraversal(root->right, ans);
		}
	}

	//solution 2：迭代法
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> stk;
		while (root != nullptr || !stk.empty()) {			//当前root非空或者栈非空
			while (root != nullptr) {						//先考虑当前节点非空的情况，当前节点为空后才去考虑栈顶元素
				stk.push(root);
				root = root->left;
			}
			//当前root为空后弹出栈顶元素开始存入ans，再考虑其右子树
			root = stk.top();
			stk.pop();
			ans.push_back(root->val);
			root = root->right;
		}
		return ans;
	}
};
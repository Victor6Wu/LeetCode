//验证二叉搜索树
#include"TreeNode.h";
#include<stack>;
using namespace std;

class Solution {
public:
	//solution 1：递归法,自编代码
	bool isValidBST1(TreeNode* root) {
		if (root == nullptr) return true;
		bool factor1 = 1, factor2 = 1, factor3 = 1, factor4 = 1;		//初始化4个判断条件
		if (root->left != nullptr) {			//考虑左子树
			factor1 = (root->left->val < root->val) && isValidBST1(root->left);
			
			TreeNode* top_right = root->left;
			while (top_right->right != nullptr) {
				top_right = top_right->right;
			}
			factor2 = top_right->val < root->val;
		}
		if (root->right != nullptr) {			//考虑右子树
			factor3 = (root->right->val > root->val) && isValidBST1(root->right);

			TreeNode* top_left = root->right;
			while (top_left->left != nullptr) {
				top_left = top_left->left;
			}
			factor4 = top_left->val > root->val;
		}

		return factor1 && factor2 && factor3 && factor4;
	}

	//solution 1:递归法，参考代码
	bool isValidBST1(TreeNode* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}
	//每个节点都有其应属于的范围，取决于其root的范围和root->val
	bool helper(TreeNode* root,long long lower,long long upper) {
		if (root == nullptr) {
			return true;
		}

		if (root->val <= lower || root->val >= upper) {
			return false;
		}
		//最关键的在于确定左右子树应该给的范围
		return	helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
	}

	//solution 2:中序遍历法
	bool isValidBST2(TreeNode* root) {
		stack<TreeNode*> stk;
		long long inorder = (long long)INT_MIN - 1;		//构建一个最小的数值，要比INT_MIN小才可以
		while (root != nullptr || !stk.empty()) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}

			root = stk.top();
			stk.pop();
			if (root->val <= inorder) {
				return false;
			}

			inorder = root->val;
			root = root->right;
		}
		return true;
	}
};
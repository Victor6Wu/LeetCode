//Given a binary tree, determine if it is height-balanced.
//For this problem, a height - balanced binary tree is defined as :
//a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
#include"TreeNode.h"
#include<vector>
#include<algorithm>
using namespace std;

class Soluion {
public:
	//solution 1:自顶向下递归，时间复杂度最坏O(n^2),如代码所示，计算高度需要递归，判断平衡也要递归
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	bool isBalanced1(TreeNode* root) {
		if (!root) return true;
		int leftDepth = maxDepth(root->left), rightDepth = maxDepth(root->right);
		int error = abs(leftDepth - rightDepth);
		if (error > 1) return false;
		else return isBalanced1(root->left) && isBalanced1(root->right);
	}

	//solution 2:自底向上递归，时间复杂度：O(n)，将平衡的判断转换成用高度判断
	bool isBalanced(TreeNode* root) {
		return height(root) >= 0;
	}

	int height(TreeNode* root) {
		if (!root) return 0;

		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
			return -1;
		}
		else {
			return max(leftHeight, rightHeight) + 1;	
		}
	}
};
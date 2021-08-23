//Given a binary tree, determine if it is height-balanced.
//For this problem, a height - balanced binary tree is defined as :
//a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
#include"TreeNode.h"
#include<vector>
#include<algorithm>
using namespace std;

class Soluion {
public:
	//solution 1:�Զ����µݹ飬ʱ�临�Ӷ��O(n^2),�������ʾ������߶���Ҫ�ݹ飬�ж�ƽ��ҲҪ�ݹ�
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

	//solution 2:�Ե����ϵݹ飬ʱ�临�Ӷȣ�O(n)����ƽ����ж�ת�����ø߶��ж�
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
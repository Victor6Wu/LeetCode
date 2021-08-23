//Given the root of a binary tree, check whether it is a mirror of itself 
//(i.e., symmetric around its center).
#include"TreeNode.h"
#include<queue>
using namespace std;

class Solution {
public:
	//solution 1:递归法，判断左右子树是否对称，借鉴No_100，
	bool check1(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {		//p,q均为空
			return true;
		}
		else if (left == nullptr || right == nullptr) {	//有一个为空
			return false;
		}
		else if (left->val != right->val) {		//均不为空,但值不相等	
			return false;
		}
		else {			//根节点相等
			return check(left->left, right->right) && check(left->right, right->left);
		}
	}

	bool isSymmetric1(TreeNode* root) {
		if (root == nullptr) return true;
		else if (root->left == nullptr && root->right == nullptr) {
			return true;
		}
		else if (root->left == nullptr || root->right == nullptr) {
			return false;
		}
		else {
			return check(root->left, root->right); 
		}
	}

	//solution 1+:代码改进，相较于自编代码，将root到左右子树的过程省略了
	bool check(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (!p || !q) return false;
		return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
	}

	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}

	//solution 2：迭代法,左右子树对称进行，每次从队列中取出两个紧邻的节点进行比较
	bool check2(TreeNode* left, TreeNode* right) {
		queue<TreeNode*> q;
		q.push(left);
		q.push(right);
		while (!q.empty()) {
			left = q.front(); q.pop();
			right = q.front(); q.pop();
			if (!left && !right) continue;
			if ((!left || !right) || (left->val != right->val)) return false;
			//两个节点相等
			q.push(left->left);
			q.push(right->right);

			q.push(left->right);
			q.push(right->left);
		}
		return true;
	}

	bool isSymmetric(TreeNode* root) {
		return check2(root, root);
	}
};
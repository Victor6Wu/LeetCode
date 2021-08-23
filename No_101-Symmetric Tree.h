//Given the root of a binary tree, check whether it is a mirror of itself 
//(i.e., symmetric around its center).
#include"TreeNode.h"
#include<queue>
using namespace std;

class Solution {
public:
	//solution 1:�ݹ鷨���ж����������Ƿ�Գƣ����No_100��
	bool check1(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {		//p,q��Ϊ��
			return true;
		}
		else if (left == nullptr || right == nullptr) {	//��һ��Ϊ��
			return false;
		}
		else if (left->val != right->val) {		//����Ϊ��,��ֵ�����	
			return false;
		}
		else {			//���ڵ����
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

	//solution 1+:����Ľ���������Ա���룬��root�����������Ĺ���ʡ����
	bool check(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (!p || !q) return false;
		return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
	}

	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}

	//solution 2��������,���������Գƽ��У�ÿ�δӶ�����ȡ���������ڵĽڵ���бȽ�
	bool check2(TreeNode* left, TreeNode* right) {
		queue<TreeNode*> q;
		q.push(left);
		q.push(right);
		while (!q.empty()) {
			left = q.front(); q.pop();
			right = q.front(); q.pop();
			if (!left && !right) continue;
			if ((!left || !right) || (left->val != right->val)) return false;
			//�����ڵ����
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
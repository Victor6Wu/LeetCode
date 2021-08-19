//��֤����������
#include"TreeNode.h";
#include<stack>;
using namespace std;

class Solution {
public:
	//solution 1���ݹ鷨,�Ա����
	bool isValidBST1(TreeNode* root) {
		if (root == nullptr) return true;
		bool factor1 = 1, factor2 = 1, factor3 = 1, factor4 = 1;		//��ʼ��4���ж�����
		if (root->left != nullptr) {			//����������
			factor1 = (root->left->val < root->val) && isValidBST1(root->left);
			
			TreeNode* top_right = root->left;
			while (top_right->right != nullptr) {
				top_right = top_right->right;
			}
			factor2 = top_right->val < root->val;
		}
		if (root->right != nullptr) {			//����������
			factor3 = (root->right->val > root->val) && isValidBST1(root->right);

			TreeNode* top_left = root->right;
			while (top_left->left != nullptr) {
				top_left = top_left->left;
			}
			factor4 = top_left->val > root->val;
		}

		return factor1 && factor2 && factor3 && factor4;
	}

	//solution 1:�ݹ鷨���ο�����
	bool isValidBST1(TreeNode* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}
	//ÿ���ڵ㶼����Ӧ���ڵķ�Χ��ȡ������root�ķ�Χ��root->val
	bool helper(TreeNode* root,long long lower,long long upper) {
		if (root == nullptr) {
			return true;
		}

		if (root->val <= lower || root->val >= upper) {
			return false;
		}
		//��ؼ�������ȷ����������Ӧ�ø��ķ�Χ
		return	helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
	}

	//solution 2:���������
	bool isValidBST2(TreeNode* root) {
		stack<TreeNode*> stk;
		long long inorder = (long long)INT_MIN - 1;		//����һ����С����ֵ��Ҫ��INT_MINС�ſ���
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
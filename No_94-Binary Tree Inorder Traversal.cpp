//Given the root of a binary tree, return the inorder traversal of its nodes' values.
#include"TreeNode.h"
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	//solution 1:�ݹ鷨
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

	//solution 2��������
	vector<int> inorderTraversal2(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> stk;
		while (root != nullptr || !stk.empty()) {			//��ǰroot�ǿջ���ջ�ǿ�
			while (root != nullptr) {						//�ȿ��ǵ�ǰ�ڵ�ǿյ��������ǰ�ڵ�Ϊ�պ��ȥ����ջ��Ԫ��
				stk.push(root);
				root = root->left;
			}
			//��ǰrootΪ�պ󵯳�ջ��Ԫ�ؿ�ʼ����ans���ٿ�����������
			root = stk.top();
			stk.pop();
			ans.push_back(root->val);
			root = root->right;
		}
		return ans;
	}

	//solution 3:Morris�����ռ临�Ӷ�O(1)
	vector<int> inorderTraversal3(TreeNode* root) {
		vector<int> res;
		TreeNode* predecessor = nullptr;

		while (root != nullptr) {
			if (root->left != nullptr) {
				// predecessor �ڵ���ǵ�ǰ root �ڵ�������һ����Ȼ��һֱ���������޷���Ϊֹ
				predecessor = root->left;
				while (predecessor->right != nullptr && predecessor->right != root) {//Ҫע��˴���ѭ������
					predecessor = predecessor->right;
				}

				// �� predecessor ����ָ��ָ�� root����������������
				if (predecessor->right == nullptr) {
					predecessor->right = root;
					root = root->left;
				}
				// ˵���������Ѿ��������ˣ�������Ҫ�Ͽ�����
				else {
					res.push_back(root->val);
					predecessor->right = nullptr;
					root = root->right;
				}
			}
			// ���û�����ӣ���ֱ�ӷ����Һ���
			else {
				res.push_back(root->val);
				root = root->right;
			}
		}
		return res;
	}
};
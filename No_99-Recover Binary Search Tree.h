//You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
#include"TreeNode.h";
#include<stack>;
using namespace std;

class Solution {
public:
	//solution1:��ʽ���������������
	//solution 2:��ʽ����������ڱ����Ĺ����м�¼����Ľڵ㣬���ݴ���ĸ�����ȷ�������Ľڵ㡣����ջ�����������������
	void recoverTree2(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* errorA1 = root;
		TreeNode* errorA2 = root;
		TreeNode* errorB1 = root;
		TreeNode* errorB2 = root;
		TreeNode* inorderNode = root;			//���ں�inorder�ĸ���ͬ��������inorder�Ľڵ�
		int signal = 0;
		long long inorder = (long long)INT_MIN - 1;		//����һ����С����ֵ��Ҫ��INT_MINС�ſ���
		while (root != nullptr || !stk.empty()) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}

			root = stk.top();
			stk.pop();
			//���ݵ�ǰ����ڵ������¼�³�����Ľڵ�
			if (root->val <= inorder) {
				if (signal == 0) {
					errorA1 = inorderNode;
					errorA2 = root;
					signal++;
				}
				else if(signal == 1) {
					errorB1 = inorderNode;
					errorB2 = root;
					signal++;
					break;
				}
				
			}
			//����inorder�����Ӧ�Ľڵ�
			inorder = root->val;
			inorderNode = root;
			root = root->right;
		}
		//���ݴ���ڵ����ȷ���������
		if (signal == 1) {
			int temp = errorA1->val;
			errorA1->val = errorA2->val;
			errorA2->val = temp;
		}
		else if (signal == 2) {
			int temp = errorA1->val;
			errorA1->val = errorB2->val;
			errorB2->val = temp;
		}
	}

	//solution 2:�����Ż���ʵ����ά����inorderNode��û��Ҫά��inorder��û��Ҫά��A1��A2��B1��B2�ĸ��ڵ����ڴ洢�����������ڽ����ľ������ڵ㣬����������
	void recoverTree2(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* x = nullptr;		//��¼��һ������ڵ�
		TreeNode* y = nullptr;		//��¼�ڶ�������ڵ�
		TreeNode* inorderNode = nullptr;

		while (!stk.empty() || root != nullptr) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			if (inorderNode != nullptr && root->val < inorderNode->val) {
				y = root;			//�ܹؼ���һ�㣺���ڵĽ���Ҳ�ã�������Ҳ�գ���y���ԣ����Ǽ�¼�����ĵ�ǰ�ڵ㣬������һ���ڵ㡣
				if (x == nullptr) {		//�ؼ������ݵ�ǰ��x�Ƿ�Ϊ�տ���ȷ�������ڽ������ǲ����ڽ���
					x = inorderNode;		//�ܹؼ���һ�㣺����Ҳ�ã�������Ҳ�գ�xֻ��Ҫ��¼��һ������λ�õ�ǰ��Ľڵ�
				}
				else break;
			}
			inorderNode = root;
			root = root->right;
		}
		swap(x->val, y->val);
	}

	//solution 3��Morris��,ע�������pred��ʾ���ǰ����������ʱ�Ѿ���������һ���ڵ㣬predecessor��ʾ�������������Ҳ�Ľڵ�
	void recoverTree3(TreeNode* root) {
		TreeNode* x = nullptr, * y = nullptr, * pred = nullptr, * predecessor = nullptr;
		while (root != nullptr) {
			if (root->left != nullptr) {
				predecessor = root->left;
				while (predecessor->right != nullptr && predecessor->right != root) {
					predecessor = predecessor->right;
				}

				if (predecessor->right == nullptr) {	//�������ӣ���������root��������
					predecessor->right = root;
					root = root->left;
				}
				//������ϣ��Ͽ�����
				else {
					predecessor->right = nullptr;
					if (pred != nullptr && root->val < pred->val) {
						y = root;
						if (x == nullptr) {
							x = pred;
						}

					}
					pred = root;			//�ڶ��δ����ǰ����Ҫ���ϵظ���pred��root
					root = root->right;
				}
			}
			else {
				//��ʱ��root�������������pred�����һ���ڵ㣬Ҫ�ȸ�pred���бȽϣ�ȷ���Ƿ�Ϊ����λ��
				if (pred != nullptr && root->val < pred->val) {
					y = root;
					if (x == nullptr) {
						x = pred;
					}

				}
				pred = root;			//�ڶ��δ����ǰ����Ҫ���ϵظ���pred��root
				root = root->right;
			}
		}
		swap(x->val, y->val);
	}
};
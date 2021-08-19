//You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
#include"TreeNode.h";
#include<stack>;
using namespace std;

class Solution {
public:
	//solution1:显式中序遍历，代码略
	//solution 2:隐式中序遍历，在遍历的过程中记录错误的节点，根据错误的个数，确定交换的节点。采用栈迭代法进行中序遍历
	void recoverTree2(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* errorA1 = root;
		TreeNode* errorA2 = root;
		TreeNode* errorB1 = root;
		TreeNode* errorB2 = root;
		TreeNode* inorderNode = root;			//用于和inorder的更新同步，保存inorder的节点
		int signal = 0;
		long long inorder = (long long)INT_MIN - 1;		//构建一个最小的数值，要比INT_MIN小才可以
		while (root != nullptr || !stk.empty()) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}

			root = stk.top();
			stk.pop();
			//根据当前错误节点个数记录下出问题的节点
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
			//更新inorder及其对应的节点
			inorder = root->val;
			inorderNode = root;
			root = root->right;
		}
		//根据错误节点个数确定交换情况
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

	//solution 2:代码优化，实际上维护了inorderNode就没必要维护inorder；没必要维护A1、A2、B1、B2四个节点用于存储错误，真正用于交换的就两个节点，用两个即可
	void recoverTree2(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* x = nullptr;		//记录第一个错误节点
		TreeNode* y = nullptr;		//记录第二个错误节点
		TreeNode* inorderNode = nullptr;

		while (!stk.empty() || root != nullptr) {
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			if (inorderNode != nullptr && root->val < inorderNode->val) {
				y = root;			//很关键的一点：相邻的交换也好，不相邻也罢，对y而言，都是记录错误点的当前节点，即后面一个节点。
				if (x == nullptr) {		//关键：根据当前的x是否为空可以确定是相邻交换还是不相邻交换
					x = inorderNode;		//很关键的一点：相邻也好，不相邻也罢，x只需要记录第一个错误位置的前面的节点
				}
				else break;
			}
			inorderNode = root;
			root = root->right;
		}
		swap(x->val, y->val);
	}

	//solution 3：Morris法,注意代码中pred表示的是按照中序遍历时已经排序的最后一个节点，predecessor表示的是左子树最右侧的节点
	void recoverTree3(TreeNode* root) {
		TreeNode* x = nullptr, * y = nullptr, * pred = nullptr, * predecessor = nullptr;
		while (root != nullptr) {
			if (root->left != nullptr) {
				predecessor = root->left;
				while (predecessor->right != nullptr && predecessor->right != root) {
					predecessor = predecessor->right;
				}

				if (predecessor->right == nullptr) {	//建立链接，继续遍历root的左子树
					predecessor->right = root;
					root = root->left;
				}
				//访问完毕，断开链接
				else {
					predecessor->right = nullptr;
					if (pred != nullptr && root->val < pred->val) {
						y = root;
						if (x == nullptr) {
							x = pred;
						}

					}
					pred = root;			//第二次错误点前都需要不断地更新pred和root
					root = root->right;
				}
			}
			else {
				//此时的root就是中序遍历中pred后面的一个节点，要先跟pred进行比较，确认是否为交换位置
				if (pred != nullptr && root->val < pred->val) {
					y = root;
					if (x == nullptr) {
						x = pred;
					}

				}
				pred = root;			//第二次错误点前都需要不断地更新pred和root
				root = root->right;
			}
		}
		swap(x->val, y->val);
	}
};
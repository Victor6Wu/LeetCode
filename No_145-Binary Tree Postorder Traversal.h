//Given the root of a binary tree, return the postorder traversal of its nodes' values.
#include<vector>
#include"TreeNode.h"
#include<stack>
using namespace std;

//solution1:递归法
class Solution1 {
public:
	void postorder(vector<int>& res, TreeNode* root) {
		if (root == nullptr) return;
		postorder(res, root->left);
		postorder(res, root->right);
		res.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorder(res, root);
		return res;
	}
};

//solution2:迭代法，与前序遍历不同，要先深入节点左子树，再判断右子树，一点点的往上“回溯”；比中序遍历多一个prev节点
class Solution2 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		stack<TreeNode*> stk;
		TreeNode* prev = nullptr;	//用于标记节点的右子树是否已经遍历，若已经遍历，当前root->right = prev 的
		while (root != nullptr || !stk.empty()) {
			//对于节点不为空，就要深入探索其左子树
			while (root != nullptr) {
				stk.push(root);
				root = root->left;
			}

			//直到root为空了，该入栈的也就入栈了，可以往外取出
			root = stk.top();
			stk.pop();

			//当前root的左子树是没了，但是还要看看有没有右子树，同时也要看看右子树是不是已经遍历过了；这是与中序遍历不同的点
			if (root->right == nullptr || root->right == prev) {
				//当前root的左右子树都没有或者遍历完了，输出val，更新root和prev
				res.push_back(root->val);

				prev = root;		//要将prev更新为当前的root节点，以方便其父节点判断右子树有没有遍历结束
				root = nullptr;		//一定要将root置空，否则下个循环就又跳入root了，而不能从栈中重新取出一个节点
			}
			else {
				//右子树没搞定，深入右子树
				stk.push(root);
				root = root->right;
			}
		}
		return res;
	}
};

//solution3:morris法
class Solution {
public:
	//逆序打印head子树的右边界，所谓右边界，其实可以看成是链表，只不过把->next改成了->right
	void postMorris(vector<int>& res, TreeNode* head) {
		//需要先将“链表”翻转，然后再打印
		TreeNode* reverseNode = reverseList(head);
		TreeNode* curr = reverseNode;
		while (curr != nullptr) {
			res.push_back(curr->val);
			curr = curr->right;
		}
		//再翻转回来
		reverseList(reverseNode);
	}


	//翻转子树的右边界
	TreeNode* reverseList(TreeNode* head) {
		TreeNode* prev = nullptr;
		TreeNode* curr = head;
		while (curr != nullptr) {
			TreeNode* next = curr->right;
			curr->right = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* p1 = root;
		TreeNode* p2 = nullptr;
		while (p1 != nullptr) {
			p2 = p1->left;
			if (p2 != nullptr) {
				while (p2->right != nullptr && p2->right != p1) {
					p2 = p2->right;
				}
				if (p2->right == nullptr) {
					p2->right = p1;
					p1 = p1->left;
				}
				else {
					p2->right = nullptr;
					//在第二次访问这个predecessor节点的时候，
					postMorris(res, p1->left);		//注意，此处逆序打印root的左子树的右边界
					p1 = p1->right;
				}
			}
			else {
				p1 = p1->right;
			}
		}
		postMorris(res, root);		//最后要对root的右边界也逆序打印一次，也可以用另一种方法，让root作为dummy节点的左孩子，对dummy进行上述遍历
		return res;
	}
};
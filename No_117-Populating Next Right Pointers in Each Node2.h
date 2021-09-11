//No_116进阶版
//a binary tree.
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.
#include<queue>
using namespace std;

struct Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	//solution 1:自编代码，利用队列，空间复杂度O(N)
	Node* connect1(Node* root) {
		if (root == nullptr) return root;
		queue<Node*> Q;
		Q.push(root);
		while (!Q.empty()) {
			int n = Q.size();
			for (int i = 0; i < n; i++) {
				auto node = Q.front();	Q.pop();
				if (i < n - 1) {
					node->next = Q.front();
				}
				if (node->left != nullptr) {
					Q.push(node->left);
				}
				if (node->right != nullptr) {
					Q.push(node->right);
				}
			}
		}
		return root;
	}

	//solution 2:使用已建立的next指针
	void handle(Node*& last, Node*& p, Node*& nextStart) {			//last表示当前链接层的最后一个已链接节点；p是被链接节点；nextStar是当前链接层的头节点
		//如果last不是空，p可以直接接后面
		if (last) {
			last->next = p;
		}
		//如果nextStar是空的，在第一次输入p时，将其设为nextStar，作为该层的头节点
		if (!nextStart) {
			nextStart = p;
		}
		//更新last
		last = p;
	}

	Node* connect(Node* root) {
		if (!root) return root;
		Node* star = root;		//每层的头节点
		while (star) {
			Node* last = nullptr, * nextStar = nullptr;		//初始化，一次循环就重新创建一次
			for (Node* p = star; p != nullptr; p = p->next) {
				if (p->left) {
					handle(last, p->left, nextStar);
				}

				if (p->right) {
					handle(last, p->right, nextStar);
				}
			}
			star = nextStar;
		}
		return root;
	}
};
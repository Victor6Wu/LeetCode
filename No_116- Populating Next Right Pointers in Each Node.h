//a perfect binary tree.
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.
#include<queue>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
};

class Solution {
public:
	//solution 1:自编代码，广度优先搜索
	Node* connect1(Node* root) {
		if (root == nullptr) return root;
		queue<Node*> Q;
		Q.push(root);
		while (!Q.empty()) {
			int n = Q.size();
			auto first = Q.front(); Q.pop();
			if (first->left != nullptr) {
				Q.push(first->left);
				Q.push(first->right);
			}
			for (int i = 1; i < n; i++) {
				auto second = Q.front();	Q.pop();
				if (second->left != nullptr) {
					Q.push(second->left);
					Q.push(second->right);
				}
				first->next = second;
				first = second;
			}
			first->next = nullptr;
		}
		return root;
	}

	//solution 2:sln 1的修改版，不需要first和second，空间复杂度O(N)
	Node* connect2(Node* root) {
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
					Q.push(node->right);
				}
			}
		}
		return root;
	}

	//solution 3:使用已建立的next指针，空间复杂度O(1)
	Node* connect3(Node* root) {
		if (root == nullptr || root->left == nullptr) return root;
		Node* head = root;
		while (head->left != nullptr) {
			Node* next_node = head;
			while (next_node->next != nullptr) {		//只有第一层是一个节点，下面的层都是可以进入循环的，一直循环到每层的最后一个节点
				next_node->left->next = next_node->right;	//建立内链接
				next_node->right->next = next_node->next->left;		//建立外链接
				next_node = next_node->next;			//后移节点
			}	
			//处理最后一个节点
			next_node->left->next = next_node->right;
			head = head->left;
		}
		return root;
	}
};
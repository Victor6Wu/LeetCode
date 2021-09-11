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
	//solution 1:�Ա���룬�����������
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

	//solution 2:sln 1���޸İ棬����Ҫfirst��second���ռ临�Ӷ�O(N)
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

	//solution 3:ʹ���ѽ�����nextָ�룬�ռ临�Ӷ�O(1)
	Node* connect3(Node* root) {
		if (root == nullptr || root->left == nullptr) return root;
		Node* head = root;
		while (head->left != nullptr) {
			Node* next_node = head;
			while (next_node->next != nullptr) {		//ֻ�е�һ����һ���ڵ㣬����Ĳ㶼�ǿ��Խ���ѭ���ģ�һֱѭ����ÿ������һ���ڵ�
				next_node->left->next = next_node->right;	//����������
				next_node->right->next = next_node->next->left;		//����������
				next_node = next_node->next;			//���ƽڵ�
			}	
			//�������һ���ڵ�
			next_node->left->next = next_node->right;
			head = head->left;
		}
		return root;
	}
};
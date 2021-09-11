//No_116���װ�
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
	//solution 1:�Ա���룬���ö��У��ռ临�Ӷ�O(N)
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

	//solution 2:ʹ���ѽ�����nextָ��
	void handle(Node*& last, Node*& p, Node*& nextStart) {			//last��ʾ��ǰ���Ӳ�����һ�������ӽڵ㣻p�Ǳ����ӽڵ㣻nextStar�ǵ�ǰ���Ӳ��ͷ�ڵ�
		//���last���ǿգ�p����ֱ�ӽӺ���
		if (last) {
			last->next = p;
		}
		//���nextStar�ǿյģ��ڵ�һ������pʱ��������ΪnextStar����Ϊ�ò��ͷ�ڵ�
		if (!nextStart) {
			nextStart = p;
		}
		//����last
		last = p;
	}

	Node* connect(Node* root) {
		if (!root) return root;
		Node* star = root;		//ÿ���ͷ�ڵ�
		while (star) {
			Node* last = nullptr, * nextStar = nullptr;		//��ʼ����һ��ѭ�������´���һ��
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
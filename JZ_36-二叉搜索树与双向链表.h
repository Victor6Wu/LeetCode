//����һ�ö��������������ö���������ת����һ�������˫������
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(){}
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

//DFS�������������ʹ�ö���Ŀռ䣬���������+�����Žڵ������ֱ�۵ķ���
//���ɶ���Ŀռ䣬��Ҫ֪����Щ�ڵ�����ӹ�ϵ�����ڸ��ڵ�root��ʵ������Ҫ���������������ҽڵ㽨��˫�����ӣ�����������������ڵ㽨��˫������
//��ô��������ú�������������������������ɺ���ܽ�����������
class Solution {
public:
    //�������
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        if (root->left) {
            Node* pre = root->left;
            while (pre->right != nullptr) {
                pre = pre->right;
            }
            pre->right = root;
            root->left = pre;
        }
        if (root->right) {
            Node* next = root->right;
            while (next->left != nullptr) {
                next = next->left;
            }
            next->left = root;
            root->right = next;
        }
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        Node* head = root, * tail = root;
        while (head->left != nullptr) {
            head = head->left;
        }
        while (tail->right != nullptr) {
            tail = tail->right;
        }
        dfs(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
};
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
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

//DFS，如果本题允许使用额外的空间，用中序遍历+数组存放节点是最简单直观的方法
//不采额外的空间，需要知道这些节点的连接关系，对于根节点root，实际上是要和其左子树的最右节点建立双向连接；与其右子树的最左节点建立双向连接
//那么，必须采用后续遍历，待左右子树操作完成后才能建立上述连接
class Solution {
public:
    //后序遍历
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
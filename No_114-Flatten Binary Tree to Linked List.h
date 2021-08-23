//Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//The "linked list" should be in the same order as a pre - order traversal of the binary tree.
#include"TreeNode.h"
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    //solution 1:递归法，前序遍历可以采用递归，或者迭代（迭代需要利用stack回溯），遍历与展开分离
    void pre_order(TreeNode* root, vector<TreeNode*> &Q) {          //vector要采用引用类型
        if (!root) return;
        Q.push_back(root);
        pre_order(root->left, Q);
        pre_order(root->right, Q);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> Q;        //先存储先序遍历的结果
        pre_order(root, Q);
        //再展开
        for (int i = 1; i < Q.size(); i++) {    //注意此处i从1开始
            root = Q[i-1];
            root->left = nullptr;
            root->right = Q[i];
        }
    }

    //solution 2：前序遍历与展开同步进行，关键在于每次链接的时候要将当前节点的左右孩子单独取出
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = nullptr;       //创建先驱节点
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            //将取出的节点与前一个点衔接
            if (prev) {
                prev->left = nullptr;
                prev->right = curr;
            }

            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
            //更新prev
            prev = curr;
        }
    }

    //solution 3:根据先序遍历的特点，将左子树最右节点接到右子树根节点前
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* next = curr->left;
                TreeNode* predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};
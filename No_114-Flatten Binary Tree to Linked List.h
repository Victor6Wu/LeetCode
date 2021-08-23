//Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//The "linked list" should be in the same order as a pre - order traversal of the binary tree.
#include"TreeNode.h"
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    //solution 1:�ݹ鷨��ǰ��������Բ��õݹ飬���ߵ�����������Ҫ����stack���ݣ���������չ������
    void pre_order(TreeNode* root, vector<TreeNode*> &Q) {          //vectorҪ������������
        if (!root) return;
        Q.push_back(root);
        pre_order(root->left, Q);
        pre_order(root->right, Q);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> Q;        //�ȴ洢��������Ľ��
        pre_order(root, Q);
        //��չ��
        for (int i = 1; i < Q.size(); i++) {    //ע��˴�i��1��ʼ
            root = Q[i-1];
            root->left = nullptr;
            root->right = Q[i];
        }
    }

    //solution 2��ǰ�������չ��ͬ�����У��ؼ�����ÿ�����ӵ�ʱ��Ҫ����ǰ�ڵ�����Һ��ӵ���ȡ��
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = nullptr;       //���������ڵ�
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            //��ȡ���Ľڵ���ǰһ�����ν�
            if (prev) {
                prev->left = nullptr;
                prev->right = curr;
            }

            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
            //����prev
            prev = curr;
        }
    }

    //solution 3:��������������ص㣬�����������ҽڵ�ӵ����������ڵ�ǰ
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
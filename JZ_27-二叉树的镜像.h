//请完成一个函数，输入一个二叉树，该函数输出它的镜像。
#include"TreeNode.h"
using namespace std;

//递归法，将每个节点的左右子树调换，并且对孩子节点也执行相同的操作
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* tmp_left = mirrorTree(root->left);
        TreeNode* tmp_right = mirrorTree(root->right);
        root->left = tmp_right;
        root->right = tmp_left;
        return root;
    }
};

//代码2
class Solution {
public:
    void mirror(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirror(root->left);
        mirror(root->right);
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;
        mirror(root);
        return root;
    }
};
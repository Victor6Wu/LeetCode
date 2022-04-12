//�����һ������������һ�����������ú���������ľ���
#include"TreeNode.h"
using namespace std;

//�ݹ鷨����ÿ���ڵ�������������������ҶԺ��ӽڵ�Ҳִ����ͬ�Ĳ���
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

//����2
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
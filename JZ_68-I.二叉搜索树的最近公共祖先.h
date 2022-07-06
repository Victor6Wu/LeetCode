//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。（一个节点也可以是它自己的祖先）
#include<vector>
#include<queue>
#include"TreeNode.h"
using namespace std;

//自编错误代码，这只是一个二叉搜索树，父子节点的关系不满足i 与 2i + 1, 2i + 2，
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
            vector<TreeNode*> levelOrder;
        queue<TreeNode*> Q;
        Q.push(root);
        int a, b;
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            levelOrder.push_back(node);
            if (node == p) a = levelOrder.size() - 1;
            else if (node == q) b = levelOrder.size() - 1;
            if (node) {
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        while (a != b) {
            if (a < b) b = (b - 1) / 2;
            else a = (a - 1) / 2;
        }
        return levelOrder[a];
    }
};

//利用二叉搜索树的特点，从root节点进行搜索，找到第一个分叉点即最近的公共祖先
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val, b = q->val;
        while (root != nullptr) {
            if (root->val > a && root->val > b) root = root->left;
            else if (root->val < a && root->val < b) root = root->right;
            else break;
        }
        return root;
    }
};
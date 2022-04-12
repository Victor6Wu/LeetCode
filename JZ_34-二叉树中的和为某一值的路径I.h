//给定一个二叉树root和一个值 sum ，判断是否有从根节点到叶子节点的节点值之和等于 sum 的路径。
#include"TreeNode.h"
using namespace std;

class Solution {
public:
    bool dfs(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) {
            if (sum == 0) return true;
            else return false;
        }
        return dfs(root->left, sum) || dfs(root->right, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
};
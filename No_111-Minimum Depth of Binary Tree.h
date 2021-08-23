//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#include"TreeNode.h"
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    //solution 1:深度优先搜索,递归方法
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right)   return 1;
        if (!root->left)    return minDepth(root->right) + 1;
        if (!root->right)    return minDepth(root->left) + 1;
        else    return min(minDepth(root->left), minDepth(root->right)) + 1;
    } 

    //solution 2:广度优先搜索,最先找到的叶子节点的深度就是二叉树的最小深度，所以层层搜索叶节点即可
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> Q;
        int depth = 1;
        Q.push(root);

        while (!Q.empty()) {
            int m = Q.size();
            for (int i = 0; i < m; i++) {
                root = Q.front();
                Q.pop();
                if (root->left) Q.push(root->left);
                if (root->right) Q.push(root->right);
                if (!root->left && !root->right)   return depth;
            }
            depth++;
        }
    }
};
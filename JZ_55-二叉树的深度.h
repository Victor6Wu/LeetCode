//输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
#include"TreeNode.h"
#include<algorithm>
#include<queue>
using namespace std;

//DFS前序遍历，参照JZ_34题的方法2
class Solution1 {
private:
    int maxdepth = 0;
public:
    void dfs(TreeNode* root, int tmpDepth) {
        if (root == nullptr) return;
        tmpDepth++;
        if (root->left == nullptr && root->right == nullptr) maxdepth = max(maxdepth, tmpDepth);
        dfs(root->left, tmpDepth);
        dfs(root->right, tmpDepth);
        tmpDepth--;
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return maxdepth;
    }
};

//DFS后序遍历
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//BFS，层层往下，只要有一层，就可以深度+1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int count = q.size();
            while (count > 0) {
                TreeNode* it = q.front();
                q.pop();
                count--;
                if (it->left) q.push(it->left);
                if (it->right) q.push(it->right);
            }
            res++;
        }
        return res;
    }
};
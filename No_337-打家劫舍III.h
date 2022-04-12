//房子以二叉树的方式连接
#include<vector>
#include<unordered_map>
#include"TreeNode.h"
using namespace std;

//递归法，要用一定的空间记忆递归的过程结果，避免重复计算
class Solution {
public:
    unordered_map<TreeNode*, int> umap;     //存储计算过的节点
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (umap[root]) return umap[root];  
        int res1 = rob(root->left) + rob(root->right);  //情况1，不考虑root节点
        //情况2，考虑root节点
        int res2 = root->val;
        if (root->left != nullptr) {
            res2 += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            res2 += rob(root->right->left) + rob(root->right->right);
        }
        //记录当前节点的计算结果
        umap[root] = max(res1, res2);
        return max(res1, res2);
    }
};

//动态规划法，递归的方式进行后续遍历，关键在于每次返回一个长度为2的数组，存储：考虑该节点、不考虑该节点能得到的最大金额
class Solution2 {
public:
    int rob(TreeNode* root) {
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);       //考虑与不考虑中的大者
    }

    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) return { 0, 0 };
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //情况1，考虑cur节点
        int res1 = cur->val + left[1] + right[1];
        //情况2，不考虑cur节点，那么左右孩子既可以考虑也可以不考虑
        int res2 = max(left[0], left[1]) + max(right[0], right[1]);

        return { res1, res2 };
    }
};

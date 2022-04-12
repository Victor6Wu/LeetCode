//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
#include"TreeNode.h"
#include<vector>
using namespace std;

//错误答案，中序变量的结果，判断数组是否对称
class Solution {
private:
    vector<int> nums;
public:
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    bool isSymmetric(TreeNode* root) {
        dfs(root);
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            if (nums[i] != nums[j]) return false;
        }
        return true;
    }
};

//从顶至底递归
class Solution {
public:
    bool core(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        else if ((left && !right) || (!left && right)) return false;
        if (left->val != right->val) return false;
        else return core(left->left, right->right) && core(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        return core(root->left, root->right);
    }
};
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
#include<vector>
#include"TreeNode.h"
using namespace std;

//回溯的思想
class Solution1 {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void backTracking(TreeNode* root, int tmpSum, int target) {
        tmpSum += root->val;
        tmp.push_back(root->val);
        if (!root->left && !root->right) {
            if (tmpSum == target) {
                ans.push_back(tmp);
            }
            return;
        }

        if (root->left) {
            backTracking(root->left, tmpSum, target);
            tmp.pop_back();
        }

        if (root->right) {
            backTracking(root->right, tmpSum, target);
            tmp.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return {};
        backTracking(root, 0, target);
        return ans;
    }
};

//代码改进，将判断节点是否为空同，放在dfs函数的开头进行判断
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void dfs(TreeNode* root, int target) {
        if (root == nullptr) return;        //只在遇到空节点的时候返回
        tmp.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right && target == 0) {
            ans.push_back(tmp);
        }

        dfs(root->left, target);
        dfs(root->right, target);
        tmp.pop_back();     //只需要弹出局部空间中进行的tmp.push_back(root->val)操作
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};
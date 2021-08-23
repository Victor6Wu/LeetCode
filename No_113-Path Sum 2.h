//Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
#include"TreeNode.h"
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    //solution 1：深度、广度优先搜索，借用No_112，queue和stack替换
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> ans;
        int sum = 0;
        vector<int> path;
        stack<pair<pair<TreeNode*, int>, vector<int>>>  table; //成对存储子节点和已经计算的路径和，不一定用这种形式，两个并行的栈也可
        table.push(make_pair(make_pair(root, sum), path));
        while (!table.empty()) {
            auto it = table.top(); table.pop();
            root = it.first.first;
            sum = it.first.second;
            path = it.second;
            //将当前节点加入路径
            sum += root->val;           
            path.push_back(root->val);
            if (!root->left && !root->right) {
                if (sum == targetSum) {
                    ans.push_back(path);
                }
                else continue;              //找到了一个叶子节点，但是路径总和不等于目标值，进行下一次循环
            }
            //右孩子入栈
            if (root->right) {
                table.push(make_pair(make_pair(root->right, sum), path));
            }
            //左孩子入栈
            if (root->left) {
                table.push(make_pair(make_pair(root->left, sum), path));
            }
        }
        return ans;
    }

    //solution 2:递归法
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0) {
            ret.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();        //无论上面两个dfs下有没有成功的路径，此处都要回退到该节点的父节点
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
};
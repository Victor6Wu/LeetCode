//Given the root of a binary tree and an integer targetSum,
//return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
#include"TreeNode.h"
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    //solution 1:自编代码，深度优先搜索，找到叶节点再判断总和
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        int sum = 0;
        stack<pair<TreeNode*, int>>  table; //成对存储子节点和已经计算的路径和，不一定用这种形式，两个并行的栈也可
        table.push(make_pair(root, sum));
        while (!table.empty()) {
            auto it = table.top(); table.pop();
            root = it.first;
            sum = it.second;
            sum += root->val;           //将当前节点val加入路径
            if (!root->left && !root->right) {
                if (sum == targetSum) return true;
                else continue;              //找到了一个叶子节点，但是路径总和不等于目标值，进行下一次循环
            }
            //右孩子入栈
            if (root->right) {
                table.push(make_pair(root->right, sum));
            }
            //左孩子入栈
            if (root->left) {
                table.push(make_pair(root->left, sum));
            }
        }
        return false;
    }

    //solution 2:广度优先搜索，将stack改成queue即可
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        int sum = 0;
        queue<pair<TreeNode*, int>>  table; //成对存储子节点和已经计算的路径和，不一定用这种形式，两个并行的栈也可
        table.push(make_pair(root, sum));
        while (!table.empty()) {
            auto it = table.front(); table.pop();
            root = it.first;
            sum = it.second;
            sum += root->val;           //将当前节点val加入路径
            if (!root->left && !root->right) {
                if (sum == targetSum) return true;
                else continue;              //找到了一个叶子节点，但是路径总和不等于目标值，进行下一次循环
            }
            //右孩子入栈
            if (root->right) {
                table.push(make_pair(root->right, sum));
            }
            //左孩子入栈
            if (root->left) {
                table.push(make_pair(root->left, sum));
            }
        }
        return false;
    }

    //solution 3:递归法，判断根到叶路径总和转换成当前节点到叶节点路径之和是否为targetSum-sum
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
    }
};
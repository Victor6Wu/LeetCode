//输入一棵节点数为 n 二叉树，判断该二叉树是否是平衡二叉树。
//在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
//平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
#include"TreeNode.h"
#include<algorithm>
#include<unordered_map>
using namespace std;

//递归法
class Solution1 {
public:
    int TreeHeight(TreeNode* root) {
        if (!root) return 0;
        int leftH = TreeHeight(root->left);
        int rightH = TreeHeight(root->right);
        return max(leftH, rightH) + 1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int leftH = TreeHeight(pRoot->left);
        int rightH = TreeHeight(pRoot->right);
        if (abs(leftH - rightH) > 1) return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};

//优化方法，空间换时间，把计算树高的结果存起来
class Solution2 {
private:
    unordered_map<TreeNode*, int> memory;
public:
    int TreeHeight(TreeNode* root) {
        if (!root) return 0;
        auto it = memory.find(root);
        if (it != memory.end()) {
            return it->second;
        }
        else {
            int leftH = TreeHeight(root->left);
            int rightH = TreeHeight(root->right);
            int height = max(leftH, rightH) + 1;
            memory[root] = height;
            return height;
        }
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int leftH = TreeHeight(pRoot->left);
        int rightH = TreeHeight(pRoot->right);
        if (abs(leftH - rightH) > 1) return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};

//自底向上方法，将计算树高和判断平衡的过程放在一起考虑：如果平衡就返回树高，如果不平衡就返回-1
class Solution3 {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        return getHeight(pRoot) >= 0; // 若结果不是-1，则是平衡的
    }
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        // 左子树高度
        int left = getHeight(root->left);
        if (left == -1)
            return -1; // 若左子树高度为-1，则不平衡
        int right = getHeight(root->right); // 右子树高度
        if (right == -1 || abs(left - right) >= 2)
            return -1; // 若右子树高度为-1，或左右子树高度之差大于1，则不平衡
        return 1 + max(left, right); // 返回该结点高度
    }
};
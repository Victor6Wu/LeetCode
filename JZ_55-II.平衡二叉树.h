//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
#include"TreeNode.h"
#include<algorithm>
using namespace std;

//平衡二叉树，不仅要子树深度差不超过1，还要求子树也是平衡二叉树
//递归法，时间复杂度O(N2)，空间复杂度O(N)
class Solution {
public:
    int high(TreeNode* root) {
        if (!root) return 0;
        return max(high(root->left), high(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(high(root->left) - high(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right) ? true : false;
    }
};

//自底向上的递归法，其实就是后续遍历，每个点只用遍历一次即可，对于不平衡的就返回深度-1，最后看root的深度是不是-1即可
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int heightleft = height(root->left);
        int heightright = height(root->right);
        if (heightleft == -1 || heightright == -1 || abs(heightleft - heightright) > 1) return  -1;
        return max(heightleft, heightright) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
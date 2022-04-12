//给定一个二叉搜索树，请找出其中第K大的节点值
#include"TreeNode.h"
#include<vector>
using namespace std;

//思路很简单，中序遍历的倒叙，找第k大，找到后提前终止搜索
//方法1,递归写法，记录一下当前第几大
class Solution1 {
private:
    int ans;
    int count = 0;
public:
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (count == 0) return;

        dfs(root->right);
        if (count == 1) {
            ans = root->val;
        }
        count--;
        dfs(root->left);
    }

    int kthLargest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ans;
    }
};

//中序遍历，记录在数组中，最后取出
class Solution2 {
public:
    vector<int> ans;
    void dfs(TreeNode* root)
    {
        if (root->left)
            dfs(root->left);
        ans.push_back(root->val);
        if (root->right)
            dfs(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return ans[ans.size() - k];
    }
};
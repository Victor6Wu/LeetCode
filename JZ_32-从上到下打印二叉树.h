//从上到下打印二叉树的每个节点，同层的节点按照从左到右的顺序打印
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//单纯的层序遍历，借用一下queue
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* it = q.front();
            q.pop();
            ans.push_back(it->val);
            if (it->left) q.push(it->left);
            if (it->right) q.push(it->right);
        }
        return ans;
    }
};
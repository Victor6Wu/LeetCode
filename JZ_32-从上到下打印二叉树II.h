//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//说白了就是层序遍历，只不过要逐层考虑一下输出数组
//递归写法
class Solution {
public:
    void printNode(vector<vector<int>>& ans, queue<TreeNode*> q) {
        if (q.empty()) return;
        int count = q.size();
        vector<int> tmp;
        while (count > 0) {
            TreeNode* it = q.front();
            q.pop();
            if (it != nullptr) {
                tmp.push_back(it->val);
                if (it->left) q.push(it->left);
                if (it->right) q.push(it->right);
            }
            count--;
        }
        ans.push_back(tmp);
        printNode(ans, q);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        printNode(ans, q);
        return ans;
    }
};

//迭代写法
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            tmp = {};
            while (count > 0) {
                TreeNode* it = q.front();
                q.pop();
                if (it != nullptr) {        //这个判断条件可以删除
                    tmp.push_back(it->val);
                    if (it->left) q.push(it->left);
                    if (it->right) q.push(it->right);
                }
                count--;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
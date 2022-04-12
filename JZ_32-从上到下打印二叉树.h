//���ϵ��´�ӡ��������ÿ���ڵ㣬ͬ��Ľڵ㰴�մ����ҵ�˳���ӡ
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//�����Ĳ������������һ��queue
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
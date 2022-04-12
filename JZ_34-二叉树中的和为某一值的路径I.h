//����һ��������root��һ��ֵ sum ���ж��Ƿ��дӸ��ڵ㵽Ҷ�ӽڵ�Ľڵ�ֵ֮�͵��� sum ��·����
#include"TreeNode.h"
using namespace std;

class Solution {
public:
    bool dfs(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) {
            if (sum == 0) return true;
            else return false;
        }
        return dfs(root->left, sum) || dfs(root->right, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
};
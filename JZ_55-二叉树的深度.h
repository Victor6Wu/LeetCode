//����һ�ö������ĸ��ڵ㣬���������ȡ��Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
#include"TreeNode.h"
#include<algorithm>
#include<queue>
using namespace std;

//DFSǰ�����������JZ_34��ķ���2
class Solution1 {
private:
    int maxdepth = 0;
public:
    void dfs(TreeNode* root, int tmpDepth) {
        if (root == nullptr) return;
        tmpDepth++;
        if (root->left == nullptr && root->right == nullptr) maxdepth = max(maxdepth, tmpDepth);
        dfs(root->left, tmpDepth);
        dfs(root->right, tmpDepth);
        tmpDepth--;
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return maxdepth;
    }
};

//DFS�������
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//BFS��������£�ֻҪ��һ�㣬�Ϳ������+1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int count = q.size();
            while (count > 0) {
                TreeNode* it = q.front();
                q.pop();
                count--;
                if (it->left) q.push(it->left);
                if (it->right) q.push(it->right);
            }
            res++;
        }
        return res;
    }
};
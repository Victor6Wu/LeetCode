//����һ������������, �ҵ�����������ָ���ڵ������������ȡ���һ���ڵ�Ҳ���������Լ������ȣ�
#include<vector>
#include<queue>
#include"TreeNode.h"
using namespace std;

//�Ա������룬��ֻ��һ�����������������ӽڵ�Ĺ�ϵ������i �� 2i + 1, 2i + 2��
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
            vector<TreeNode*> levelOrder;
        queue<TreeNode*> Q;
        Q.push(root);
        int a, b;
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            levelOrder.push_back(node);
            if (node == p) a = levelOrder.size() - 1;
            else if (node == q) b = levelOrder.size() - 1;
            if (node) {
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        while (a != b) {
            if (a < b) b = (b - 1) / 2;
            else a = (a - 1) / 2;
        }
        return levelOrder[a];
    }
};

//���ö������������ص㣬��root�ڵ�����������ҵ���һ���ֲ�㼴����Ĺ�������
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val, b = q->val;
        while (root != nullptr) {
            if (root->val > a && root->val > b) root = root->left;
            else if (root->val < a && root->val < b) root = root->right;
            else break;
        }
        return root;
    }
};
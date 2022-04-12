//�����Զ������ķ�ʽ����
#include<vector>
#include<unordered_map>
#include"TreeNode.h"
using namespace std;

//�ݹ鷨��Ҫ��һ���Ŀռ����ݹ�Ĺ��̽���������ظ�����
class Solution {
public:
    unordered_map<TreeNode*, int> umap;     //�洢������Ľڵ�
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (umap[root]) return umap[root];  
        int res1 = rob(root->left) + rob(root->right);  //���1��������root�ڵ�
        //���2������root�ڵ�
        int res2 = root->val;
        if (root->left != nullptr) {
            res2 += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            res2 += rob(root->right->left) + rob(root->right->right);
        }
        //��¼��ǰ�ڵ�ļ�����
        umap[root] = max(res1, res2);
        return max(res1, res2);
    }
};

//��̬�滮�����ݹ�ķ�ʽ���к����������ؼ�����ÿ�η���һ������Ϊ2�����飬�洢�����Ǹýڵ㡢�����Ǹýڵ��ܵõ��������
class Solution2 {
public:
    int rob(TreeNode* root) {
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);       //�����벻�����еĴ���
    }

    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) return { 0, 0 };
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //���1������cur�ڵ�
        int res1 = cur->val + left[1] + right[1];
        //���2��������cur�ڵ㣬��ô���Һ��Ӽȿ��Կ���Ҳ���Բ�����
        int res2 = max(left[0], left[1]) + max(right[0], right[1]);

        return { res1, res2 };
    }
};

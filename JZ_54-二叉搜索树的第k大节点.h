//����һ�����������������ҳ����е�K��Ľڵ�ֵ
#include"TreeNode.h"
#include<vector>
using namespace std;

//˼·�ܼ򵥣���������ĵ����ҵ�k���ҵ�����ǰ��ֹ����
//����1,�ݹ�д������¼һ�µ�ǰ�ڼ���
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

//�����������¼�������У����ȡ��
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
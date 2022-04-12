//���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//˵���˾��ǲ��������ֻ����Ҫ��㿼��һ���������
//�ݹ�д��
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

//����д��
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
                if (it != nullptr) {        //����ж���������ɾ��
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
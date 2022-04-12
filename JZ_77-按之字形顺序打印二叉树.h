//��������ӡ��Ҫ���ӡ˳���մ����Һʹ��ҵ��������
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//����һ����ת��־���ڽ���ʱ����tmp����ans֮ǰ�ж�һ���Ƿ�ת����
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<TreeNode*> q;
        bool sign = false;       //���ҵ���ı�־
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
            if (sign) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
            sign = !sign;
        }

        return ans;
    }
};
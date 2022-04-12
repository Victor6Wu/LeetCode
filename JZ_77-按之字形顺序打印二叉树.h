//还是逐层打印，要求打印顺序按照从左到右和从右到左交替进行
#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//设置一个翻转标志，在将临时数组tmp加入ans之前判断一下是否翻转即可
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<TreeNode*> q;
        bool sign = false;       //从右到左的标志
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
            if (sign) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
            sign = !sign;
        }

        return ans;
    }
};
//����������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����
#include<vector>
#include"TreeNode.h"
using namespace std;

//���ݵ�˼��
class Solution1 {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void backTracking(TreeNode* root, int tmpSum, int target) {
        tmpSum += root->val;
        tmp.push_back(root->val);
        if (!root->left && !root->right) {
            if (tmpSum == target) {
                ans.push_back(tmp);
            }
            return;
        }

        if (root->left) {
            backTracking(root->left, tmpSum, target);
            tmp.pop_back();
        }

        if (root->right) {
            backTracking(root->right, tmpSum, target);
            tmp.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return {};
        backTracking(root, 0, target);
        return ans;
    }
};

//����Ľ������жϽڵ��Ƿ�Ϊ��ͬ������dfs�����Ŀ�ͷ�����ж�
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void dfs(TreeNode* root, int target) {
        if (root == nullptr) return;        //ֻ�������սڵ��ʱ�򷵻�
        tmp.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right && target == 0) {
            ans.push_back(tmp);
        }

        dfs(root->left, target);
        dfs(root->right, target);
        tmp.pop_back();     //ֻ��Ҫ�����ֲ��ռ��н��е�tmp.push_back(root->val)����
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};
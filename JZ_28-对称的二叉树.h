//��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ������ô���ǶԳƵġ�
#include"TreeNode.h"
#include<vector>
using namespace std;

//����𰸣���������Ľ�����ж������Ƿ�Գ�
class Solution {
private:
    vector<int> nums;
public:
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    bool isSymmetric(TreeNode* root) {
        dfs(root);
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            if (nums[i] != nums[j]) return false;
        }
        return true;
    }
};

//�Ӷ����׵ݹ�
class Solution {
public:
    bool core(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        else if ((left && !right) || (!left && right)) return false;
        if (left->val != right->val) return false;
        else return core(left->left, right->right) && core(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        return core(root->left, root->right);
    }
};
//Given the root of a binary tree and an integer targetSum,
//return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
#include"TreeNode.h"
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    //solution 1:�Ա���룬��������������ҵ�Ҷ�ڵ����ж��ܺ�
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        int sum = 0;
        stack<pair<TreeNode*, int>>  table; //�ɶԴ洢�ӽڵ���Ѿ������·���ͣ���һ����������ʽ���������е�ջҲ��
        table.push(make_pair(root, sum));
        while (!table.empty()) {
            auto it = table.top(); table.pop();
            root = it.first;
            sum = it.second;
            sum += root->val;           //����ǰ�ڵ�val����·��
            if (!root->left && !root->right) {
                if (sum == targetSum) return true;
                else continue;              //�ҵ���һ��Ҷ�ӽڵ㣬����·���ܺͲ�����Ŀ��ֵ��������һ��ѭ��
            }
            //�Һ�����ջ
            if (root->right) {
                table.push(make_pair(root->right, sum));
            }
            //������ջ
            if (root->left) {
                table.push(make_pair(root->left, sum));
            }
        }
        return false;
    }

    //solution 2:���������������stack�ĳ�queue����
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        int sum = 0;
        queue<pair<TreeNode*, int>>  table; //�ɶԴ洢�ӽڵ���Ѿ������·���ͣ���һ����������ʽ���������е�ջҲ��
        table.push(make_pair(root, sum));
        while (!table.empty()) {
            auto it = table.front(); table.pop();
            root = it.first;
            sum = it.second;
            sum += root->val;           //����ǰ�ڵ�val����·��
            if (!root->left && !root->right) {
                if (sum == targetSum) return true;
                else continue;              //�ҵ���һ��Ҷ�ӽڵ㣬����·���ܺͲ�����Ŀ��ֵ��������һ��ѭ��
            }
            //�Һ�����ջ
            if (root->right) {
                table.push(make_pair(root->right, sum));
            }
            //������ջ
            if (root->left) {
                table.push(make_pair(root->left, sum));
            }
        }
        return false;
    }

    //solution 3:�ݹ鷨���жϸ���Ҷ·���ܺ�ת���ɵ�ǰ�ڵ㵽Ҷ�ڵ�·��֮���Ƿ�ΪtargetSum-sum
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
    }
};
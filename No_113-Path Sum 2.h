//Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
#include"TreeNode.h"
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    //solution 1����ȡ������������������No_112��queue��stack�滻
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> ans;
        int sum = 0;
        vector<int> path;
        stack<pair<pair<TreeNode*, int>, vector<int>>>  table; //�ɶԴ洢�ӽڵ���Ѿ������·���ͣ���һ����������ʽ���������е�ջҲ��
        table.push(make_pair(make_pair(root, sum), path));
        while (!table.empty()) {
            auto it = table.top(); table.pop();
            root = it.first.first;
            sum = it.first.second;
            path = it.second;
            //����ǰ�ڵ����·��
            sum += root->val;           
            path.push_back(root->val);
            if (!root->left && !root->right) {
                if (sum == targetSum) {
                    ans.push_back(path);
                }
                else continue;              //�ҵ���һ��Ҷ�ӽڵ㣬����·���ܺͲ�����Ŀ��ֵ��������һ��ѭ��
            }
            //�Һ�����ջ
            if (root->right) {
                table.push(make_pair(make_pair(root->right, sum), path));
            }
            //������ջ
            if (root->left) {
                table.push(make_pair(make_pair(root->left, sum), path));
            }
        }
        return ans;
    }

    //solution 2:�ݹ鷨
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0) {
            ret.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();        //������������dfs����û�гɹ���·�����˴���Ҫ���˵��ýڵ�ĸ��ڵ�
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
};
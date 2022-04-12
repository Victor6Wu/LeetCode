//����һ�ýڵ���Ϊ n ���������жϸö������Ƿ���ƽ���������
//���������ֻ��Ҫ������ƽ���ԣ�����Ҫ�������ǲ������������
//ƽ���������Balanced Binary Tree���������������ʣ�����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1����������������������һ��ƽ���������
#include"TreeNode.h"
#include<algorithm>
#include<unordered_map>
using namespace std;

//�ݹ鷨
class Solution1 {
public:
    int TreeHeight(TreeNode* root) {
        if (!root) return 0;
        int leftH = TreeHeight(root->left);
        int rightH = TreeHeight(root->right);
        return max(leftH, rightH) + 1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int leftH = TreeHeight(pRoot->left);
        int rightH = TreeHeight(pRoot->right);
        if (abs(leftH - rightH) > 1) return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};

//�Ż��������ռ任ʱ�䣬�Ѽ������ߵĽ��������
class Solution2 {
private:
    unordered_map<TreeNode*, int> memory;
public:
    int TreeHeight(TreeNode* root) {
        if (!root) return 0;
        auto it = memory.find(root);
        if (it != memory.end()) {
            return it->second;
        }
        else {
            int leftH = TreeHeight(root->left);
            int rightH = TreeHeight(root->right);
            int height = max(leftH, rightH) + 1;
            memory[root] = height;
            return height;
        }
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int leftH = TreeHeight(pRoot->left);
        int rightH = TreeHeight(pRoot->right);
        if (abs(leftH - rightH) > 1) return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};

//�Ե����Ϸ��������������ߺ��ж�ƽ��Ĺ��̷���һ���ǣ����ƽ��ͷ������ߣ������ƽ��ͷ���-1
class Solution3 {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        return getHeight(pRoot) >= 0; // ���������-1������ƽ���
    }
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        // �������߶�
        int left = getHeight(root->left);
        if (left == -1)
            return -1; // ���������߶�Ϊ-1����ƽ��
        int right = getHeight(root->right); // �������߶�
        if (right == -1 || abs(left - right) >= 2)
            return -1; // ���������߶�Ϊ-1�������������߶�֮�����1����ƽ��
        return 1 + max(left, right); // ���ظý��߶�
    }
};
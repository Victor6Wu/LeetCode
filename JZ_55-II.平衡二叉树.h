//����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ������������ĳ������������ڵ���������������������1����ô������һ��ƽ���������
#include"TreeNode.h"
#include<algorithm>
using namespace std;

//ƽ�������������Ҫ������Ȳ����1����Ҫ������Ҳ��ƽ�������
//�ݹ鷨��ʱ�临�Ӷ�O(N2)���ռ临�Ӷ�O(N)
class Solution {
public:
    int high(TreeNode* root) {
        if (!root) return 0;
        return max(high(root->left), high(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(high(root->left) - high(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right) ? true : false;
    }
};

//�Ե����ϵĵݹ鷨����ʵ���Ǻ���������ÿ����ֻ�ñ���һ�μ��ɣ����ڲ�ƽ��ľͷ������-1�����root������ǲ���-1����
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int heightleft = height(root->left);
        int heightright = height(root->right);
        if (heightleft == -1 || heightright == -1 || abs(heightleft - heightright) > 1) return  -1;
        return max(heightleft, heightright) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
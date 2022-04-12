//�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)
//B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��
#include"TreeNode.h"
using namespace std;

//���������˼·��������A�����нڵ㣬���ν�����B���Ƚϣ�������ڵ�ƥ��ͼ����ݹ���жϺ��ӽڵ�
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //�ر�ע�����1.B��������λ��Ϊ�գ��򷵻�false���ڶ�A����left��right֮ǰ����Ҫ�и�������A����Ϊ��
        return  (A != nullptr && B != nullptr) && ((compareNode(A, B)) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool compareNode(TreeNode* A, TreeNode* B) {
        //B�ڴ˴�Ϊ�մ�������ƥ��Ĺ����У�B�������ˣ�Ӧ�÷���true
        if (B == nullptr) return true;
        if (A == nullptr || A->val != B->val) return false;
        return compareNode(A->left, B->left) && compareNode(A->right, B->right);
    }
};
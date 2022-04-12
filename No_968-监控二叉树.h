//����һ�������������������Ľڵ��ϰ�װ����ͷ���ڵ��ϵ�ÿ����Ӱͷ�����Լ����丸����������ֱ���Ӷ���
//�������������нڵ��������С����ͷ������
#include"TreeNode.h"
using namespace std;

class Solution {
private:
    int result;
    int traversal(TreeNode* cur) {

        // �սڵ㣬�ýڵ��и���
        if (cur == NULL) return 2;

        int left = traversal(cur->left);    // ��
        int right = traversal(cur->right);  // ��

        // ���1
        // ���ҽڵ㶼�и���
        if (left == 2 && right == 2) return 0;

        // ���2
        // left == 0 && right == 0 ���ҽڵ��޸���
        // left == 1 && right == 0 ��ڵ�������ͷ���ҽڵ��޸���
        // left == 0 && right == 1 ��ڵ����޸��ǣ��ҽڵ�����ͷ
        // left == 0 && right == 2 ��ڵ��޸��ǣ��ҽڵ㸲��
        // left == 2 && right == 0 ��ڵ㸲�ǣ��ҽڵ��޸���
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        // ���3
        // left == 1 && right == 2 ��ڵ�������ͷ���ҽڵ��и���
        // left == 2 && right == 1 ��ڵ��и��ǣ��ҽڵ�������ͷ
        // left == 1 && right == 1 ���ҽڵ㶼������ͷ
        // �������ǰ�δ�����Ѹ���
        if (left == 1 || right == 1) return 2;

        // ���ϴ�����û��ʹ��else����Ҫ��Ϊ�˰Ѹ�����֧����չ�ֳ������������������ڶ������
        // ��� return -1 �߼������ߵ����
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        // ���4
        if (traversal(root) == 0) { // root �޸���
            result++;
        }
        return result;
    }
};
//����һ�����������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���nextָ�롣
#include<iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

//����Ĺؼ��Ƕ������⣬������Ƕ�������ĳһ���ڵ㣬ϣ�����ظö���������������У������ڵ����һ���ڵ�
//ÿ���ڵ������������1.�ýڵ��Լ���Ϊ���ڵ㣬������������ô�����������һ����һ����������������ڵ�
//                  2.�ýڵ㱾����ĳһ�ڵ������������ҽڵ㣬��ô����Ҫ�����ҵ������ĳһ�ڵ㡱
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode) return NULL;
        if (pNode->right) {     //��������
            TreeLinkNode* ans = pNode->right;
            while (ans->left != nullptr) {
                ans = ans->left;
            }
            return ans;
        }
        else {                  //�����ҵ����ýڵ������ĸ��ڵ�������������ҽڵ�
            TreeLinkNode* father = pNode->next; 
            while (father && father->right == pNode) {      //ѭ�����ж��������ǣ�ʼ�������������ķ�ʽ���ӣ���ֹ������Ҫô�Ҳ�����Ҫô�ҵ���
                father = father->next;
                pNode = pNode->next;
            }
            return father;
        }
    }
};
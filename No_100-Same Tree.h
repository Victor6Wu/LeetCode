//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	//solution 1����������������ݹ鷨�����жϸ��ڵ��Ƿ���ͬ������������������
	bool isSameTree1(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {		//p,q��Ϊ��
			return true;
		}
		else if (p == nullptr || q == nullptr) {	//��һ��Ϊ��
			return false;
		}
		else if (p->val != q->val) {		//����Ϊ��,��ֵ�����	
			return false;
		}
		else {			//���ڵ����
			return isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
		}
	}

	//solution 2�������������
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        queue <TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty()) {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            if (node1->val != node2->val) {
                return false;
            }
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            if ((left1 == nullptr) ^ (left2 == nullptr)) {
                return false;
            }
            if ((right1 == nullptr) ^ (right2 == nullptr)) {
                return false;
            }
            if (left1 != nullptr) {
                queue1.push(left1);
            }
            if (right1 != nullptr) {
                queue1.push(right1);
            }
            if (left2 != nullptr) {
                queue2.push(left2);
            }
            if (right2 != nullptr) {
                queue2.push(right2);
            }
        }
        //�����������ȫһ����ѭ������ʱ��������Ӧ��ͬʱΪ��
        return queue1.empty() && queue2.empty();
    }
};
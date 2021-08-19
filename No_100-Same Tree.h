//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	//solution 1：深度优先搜索，递归法，先判断根节点是否相同，再左子树，右子树
	bool isSameTree1(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {		//p,q均为空
			return true;
		}
		else if (p == nullptr || q == nullptr) {	//有一个为空
			return false;
		}
		else if (p->val != q->val) {		//均不为空,但值不相等	
			return false;
		}
		else {			//根节点相等
			return isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
		}
	}

	//solution 2：广度优先搜索
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
        //如果两个树完全一样，循环结束时两个队列应该同时为空
        return queue1.empty() && queue2.empty();
    }
};
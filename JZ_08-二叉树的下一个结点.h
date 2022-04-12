//给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的next指针。
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

//本题的关键是读懂题意，输入的是二叉树的某一个节点，希望返回该二叉树的中序遍历中，给定节点的下一个节点
//每个节点有两种情况：1.该节点自己作为根节点，有右子树，那么中序遍历的下一个点一定其右子树的最左节点
//                  2.该节点本身是某一节点左子树的最右节点，那么必须要往上找到这个“某一节点”
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode) return NULL;
        if (pNode->right) {     //有右子树
            TreeLinkNode* ans = pNode->right;
            while (ans->left != nullptr) {
                ans = ans->left;
            }
            return ans;
        }
        else {                  //往上找到，该节点属于哪个节点的右子树的最右节点
            TreeLinkNode* father = pNode->next; 
            while (father && father->right == pNode) {      //循环的判断条件就是，始终是以右子树的方式连接；终止条件：要么找不到，要么找到了
                father = father->next;
                pNode = pNode->next;
            }
            return father;
        }
    }
};
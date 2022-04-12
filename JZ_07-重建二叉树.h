//根据给定的前序遍历和中序遍历的结果，构建二叉树并返回其根节点
#include"TreeNode.h"
#include<vector>
using namespace std;

//自编代码，根据前序遍历和中序遍历对一棵树节点的分布情况进行递归
//前序遍历的头一个元素肯定是一棵树的“根”，后面是左子树节点+右子树节点
//中序遍历被“根”分成左右两部分，分别是左子树节点和右子树节点
class Solution1 {
public:
    //root_index表示当前查询范围内（子树）的根节点；low、high表示中序遍历中的查询范围
    TreeNode* buildCore(vector<int>& preorder, vector<int>& inorder, int root_index, int low, int high) {
        if (low > high) return nullptr;
        TreeNode* tmp_root = new TreeNode(preorder[root_index]);        //创建一个根节点

        int tmp_index = low;      //左子树的节点数起始值
        //循环找到根节点在中序遍历中的位置
        while (tmp_index <= high && preorder[root_index] != inorder[tmp_index]) {
            tmp_index++;
        }
        //根据分布关系，可以推出前序遍历中，根的左孩子和右孩子的索引；两个子树节点在中序遍历中的范围
        TreeNode* leftNode = buildCore(preorder, inorder, root_index + 1, low, tmp_index - 1);
        TreeNode* rightNode = buildCore(preorder, inorder, root_index + tmp_index - low + 1, tmp_index + 1, high);
        tmp_root->left = leftNode;
        tmp_root->right = rightNode;
        return tmp_root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildCore(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};

//借用新的数组空间，相对来说更好理解
class Solution2 {
public:
    TreeNode* buildTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0) {                    //如果为空，返回NULL
            return NULL;
        }
        //依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
        vector<int> left_pre, right_pre, left_vin, right_vin;
        //前序遍历第一个节点一定为根节点
        TreeNode* head = new TreeNode(pre[0]);
        //找到中序遍历的根节点
        int root = 0;
        //遍历找到中序遍历根节点索引值
        for (int i = 0; i < pre.size(); i++) {
            if (pre[0] == vin[i]) {
                root = i;
                break;
            }
        }
        //利用中序遍历的根节点，对二叉树节点进行归并
        for (int i = 0; i < root; i++) {
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i + 1]);            //前序遍历第一个为根节点
        }

        for (int i = root + 1; i < pre.size(); i++) {
            right_vin.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }

        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        head->left = buildTree(left_pre, left_vin);
        head->right = buildTree(right_pre, right_vin);
        return head;
    }
};
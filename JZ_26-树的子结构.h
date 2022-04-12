//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//B是A的子结构， 即 A中有出现和B相同的结构和节点值。
#include"TreeNode.h"
using namespace std;

//本题的主体思路：遍历树A的所有节点，依次将其与B树比较，如果根节点匹配就继续递归的判断孩子节点
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //特别注意的是1.B如果在这个位置为空，则返回false；在对A考虑left和right之前必须要有个条件，A树不为空
        return  (A != nullptr && B != nullptr) && ((compareNode(A, B)) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool compareNode(TreeNode* A, TreeNode* B) {
        //B在此处为空代表往下匹配的过程中，B树走完了，应该返回true
        if (B == nullptr) return true;
        if (A == nullptr || A->val != B->val) return false;
        return compareNode(A->left, B->left) && compareNode(A->right, B->right);
    }
};
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
#include<vector>
using namespace std;

//本题很简单，要知道二叉搜索树后序遍历结果的特点，根节点一定在最后，前面由左子树节点和右子树节点构成；
//从后往前找到第一个小于根节点的值，那么其一定是左子树的根节点，即可确定左右子树的范围，进行同样的递归即可
//补充：找到左子树的根节点后，需要做的一件事：继续向前遍历，判断左子树中的节点是不是都小于当前的根节点，如果不是就直接返回false
class Solution {
public:
    bool core(vector<int>& postorder, int L, int R) {
        if (L >= R) return true;
        int root = postorder[R];
        int gapIndex = R - 1;
        while (gapIndex >= L) {
            if (postorder[gapIndex] < root) break;
            gapIndex--;
        }
        //判断当前根节点是否满足大于所有左子树，小于所有左子树
        for (int i = gapIndex - 1; i >= L; i--) {
            if (postorder[i] >= root) return false;
        }

        return core(postorder, L, gapIndex) && core(postorder, gapIndex + 1, R - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return core(postorder, 0, postorder.size() - 1);
    }
};
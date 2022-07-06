#include"TreeNode.h"
#include<vector>
using namespace std;

//1.根据给定的vector构造平衡二叉树，返回二叉树的根节点
TreeNode* construct_binary_tree(const vector<int>& nums) {
	//先构造一个数组存储这些元素转成的节点
	vector<TreeNode*> vecTree(nums.size(), NULL);
	TreeNode* root = NULL;
	//根据给的值创建节点，并放入数组中
	for (int i = 0; i < nums.size(); i++) {
		TreeNode* node = NULL;
		if (nums[i] != -1) node = new TreeNode(nums[i]);		//这里用-1代表null，关于将null改成-1，涉及到读取字符串的部分
		vecTree[i] = node;		//将节点填入对应的vecTree内
		if (i == 0) root = node;
	}
	//将vecTree中的节点按照二叉树的特点连接，要注意循环[的终止条件，以及节点间的关系
	for (int i = 0; i * 2 + 2 < vecTree.size(); i++) {
		if (vecTree[i] != NULL) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			vecTree[i]->right = vecTree[i * 2 + 2];
		}
	}
	return root;
}

//2.构建二叉树
//二叉树i的孩子不一定就是2i+1与2i+2了
TreeNode* deserialize(vector<int>& nums) {
	//先构造一个数组存储这些元素转成的节点
	vector<TreeNode*> nodes;
	TreeNode* root = NULL;
	//根据给的值创建节点，并放入数组中
	for (int i = 0; i < nums.size(); i++) {
		TreeNode* node = NULL;
		if (nums[i] != -1) node = new TreeNode(nums[i]);		//这里用-1代表null，关于将null改成-1，涉及到读取字符串的部分
		nodes[i] = node;		//将节点填入对应的vecTree内
		if (i == 0) root = node;
	}

    //重构二叉树的连接关系，因为是二叉树，不是平衡二叉树，所以对于空节点得记录一下，解决父子节点对应关系移位的问题
    int count = 0; //记录空节点的个数，
    for (int i = 0; 2 * (i - count) + 2 <= nodes.size(); i++) {
        if (nodes[i] == nullptr) count++;
        else {
            nodes[i]->left = nodes[2 * (i - count) + 1];        //对于平衡二叉树来说，i节点的子节点是2i+1和2i+2，但是因为是二叉树，会出现中间有空节点的情况
            nodes[i]->right = nodes[2 * (i - count) + 2];
        }
    }
    return nodes[0];
}
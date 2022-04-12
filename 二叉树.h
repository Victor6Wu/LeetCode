#include"TreeNode.h"
#include<vector>
using namespace std;

//根据给定的vector构造二叉树，返回二叉树的根节点
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
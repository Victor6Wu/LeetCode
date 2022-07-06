//给定一个节点值不重复的二叉树，查找根节点到任意指定节点的路径，该目标节点一定存在
#include"TreeNode.h"
#include<vector>
using namespace std;

//类似于后序遍历，先判断目标节点在哪个子树上，再深入探索
//缺点在于判断目标节点是否在子树上也是遍历的算法，时间复杂度很高O(N*k)
class Solution1 {
public:
	//判断目标节点在树中与否
	bool isHere(TreeNode* root, TreeNode* des) {
		if (root == nullptr) return false;
		if (root == des) return true;
		return isHere(root->left, des) || isHere(root->right, des);
	}

	//核心函数
	void core(TreeNode* root, TreeNode* des, vector<int>& path) {
		path.push_back(root->val);
		if (isHere(root->left, des)) core(root->left, des, path);
		else if(isHere(root->right, des)) core(root->right, des, path);
	}

	vector<int> getPath(TreeNode* root, TreeNode* des) {
		vector<int> path;
		core(root, des, path);
		return path;
	}
};

//递归法，一次遍历，O(n)，关键在于需要一个停止搜索的标志
class Solution2 {
private:
public:
	void core(bool& sign, TreeNode* root, TreeNode* des, vector<int>& path) {
		if (!root || sign) return;
		path.push_back(root->val);
		if (root == des) {
			sign = true;
		}
		else {
			core(sign, root->left, des, path);
			core(sign, root->right, des, path);
			if(!sign) path.pop_back();
		}
	}
	vector<int> getPath(TreeNode* root, TreeNode* des) {
		vector<int> path;
		bool sign = false;
		core(sign, root, des, path);
		return path;
	}
};

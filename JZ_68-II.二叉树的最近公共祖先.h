//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。（一个节点也可以是它自己的祖先）
#include"TreeNode.h"
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//方法1：自编代码，获取根节点到目标节点的路径，比较两个路径
//获取路径见JZ_68-拓展
class Solution1 {
public:
	void core(bool& sign, TreeNode* root, TreeNode* des, vector<TreeNode*>& path) {
		if (!root || sign) return;
		path.push_back(root);
		if (root == des) {
			sign = true;
		}
		else {
			core(sign, root->left, des, path);
			core(sign, root->right, des, path);
			if (!sign) path.pop_back();
		}
	}
	vector<TreeNode*> getPath(TreeNode* root, TreeNode* des) {
		vector<TreeNode*> path;
		bool sign = false;
		core(sign, root, des, path);
		return path;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path1 = getPath(root, p);
		vector<TreeNode*> path2 = getPath(root, q);
		TreeNode* ans;
		for (int i = 0; i < path1.size() && i < path2.size(); i++) {
			if (path1[i] == path2[i]) ans = path1[i];
			else break;
		}
		return ans;
	}
};

//方法2：递归法，将问题不断分解，再从下而上归并结果，在过程中寻找最近的公共祖先
//思路：对于一棵树root，有两个节点p、q，这两个节点可能同时在root的左子树或者又子树上，也有可能分散在左右子树上，或者其中一个就是root
//如果能够确定q、p是分散在左右子树上的，那么当前的root就是一个公共祖先，且一定是最近的那个；也有可能root就是p、q中的一个
//在递归的过程中，只会出现一次更新最近公共祖先的情况
class Solution2 {
public:
	TreeNode* ans;
	//递归函数，判断root树中是否有p或者q
	bool core(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return false;
		bool lson = core(root->left, p, q);  //左子树是否有p或q
		bool rson = core(root->right, p, q); //右子树是否有p或q
		//根据左右子树的情况，判断当前节点是否为最近的公共祖先
		//三种情况：1、p、q分散在左右子树；2.p在一个子树，q为root；3.q在一个子树，p为root
		if ((lson && rson) || (lson || rson) && (root->val == p->val || root->val == q->val)) ans = root;
		return (lson || rson) || (root->val == p->val || root->val == q->val);	//除了左右子树，可能root是p或q
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		core(root, p, q);
		return ans;
	}
};

//方法3：用散列表存储子节点到父节点的映射
//访问p，往上记录父节点；再访问q，往上寻找父节点的过程中判断是否在p的搜索记录中出现过，第一次出现的即为最近的公共祖先
class Solution2 {
private:
	unordered_map<TreeNode*, TreeNode*> father;
	unordered_map<TreeNode*, bool> visited;
public:
	//遍历，记录子父映射
	void dfs(TreeNode* root) {
		if (root == nullptr) return;
		if (root->left) {
			father[root->left] = root;
			dfs(root->left);
		}
		if (root->right) {
			father[root->right] = root;
			dfs(root->right);
		}
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		father.clear();
		visited.clear();
		dfs(root);		//建立子父映射
		while (p != nullptr) {	//记录p的寻父历程
			visited[p] = true;
			p = father[p];
		}
		while (q != nullptr) {	//q的寻父历程
			if (visited[q]) return q;
			q = father[q];
		}
		return nullptr;
	}
};
//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. 
//Return the answer in any order.
#include"TreeNode.h";
#include<vector>;
using namespace std;

class Solution {
public:
	//solution 1:回溯，个人觉得就是递归的思想
	vector<TreeNode*> generateTrees(int n) {
		if (!n) {
			return {};
		}
		return generateTrees(1, n);
	}
	//返回指定范围的数值构成的树
	vector<TreeNode*> generateTrees(int start, int end) {
		//对于没有节点的情况
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*> allTrees;
		//枚举start到end之间所有节点作为root而构成树的情况
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> leftSubTrees = generateTrees(start, i - 1);
			vector<TreeNode*> rightSubTrees = generateTrees(i + 1, end);
			//注意这里左子树和又子树又分别有多种情况，需要两重循环遍历
			for (auto& left : leftSubTrees) {
				for (auto& right : rightSubTrees) {
					TreeNode* currTree = new TreeNode(i);		//用当前值创建一个新节点
					currTree->left = left;
					currTree->right = right;
					allTrees.push_back(currTree);
				}
			}
		}
		return allTrees;
	}
};

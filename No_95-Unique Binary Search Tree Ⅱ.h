//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. 
//Return the answer in any order.
#include"TreeNode.h";
#include<vector>;
using namespace std;

class Solution {
public:
	//solution 1:���ݣ����˾��þ��ǵݹ��˼��
	vector<TreeNode*> generateTrees(int n) {
		if (!n) {
			return {};
		}
		return generateTrees(1, n);
	}
	//����ָ����Χ����ֵ���ɵ���
	vector<TreeNode*> generateTrees(int start, int end) {
		//����û�нڵ�����
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*> allTrees;
		//ö��start��end֮�����нڵ���Ϊroot�������������
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> leftSubTrees = generateTrees(start, i - 1);
			vector<TreeNode*> rightSubTrees = generateTrees(i + 1, end);
			//ע���������������������ֱַ��ж����������Ҫ����ѭ������
			for (auto& left : leftSubTrees) {
				for (auto& right : rightSubTrees) {
					TreeNode* currTree = new TreeNode(i);		//�õ�ǰֵ����һ���½ڵ�
					currTree->left = left;
					currTree->right = right;
					allTrees.push_back(currTree);
				}
			}
		}
		return allTrees;
	}
};

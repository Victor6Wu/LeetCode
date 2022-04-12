#include"TreeNode.h"
#include<vector>
using namespace std;

//���ݸ�����vector��������������ض������ĸ��ڵ�
TreeNode* construct_binary_tree(const vector<int>& nums) {
	//�ȹ���һ������洢��ЩԪ��ת�ɵĽڵ�
	vector<TreeNode*> vecTree(nums.size(), NULL);
	TreeNode* root = NULL;
	//���ݸ���ֵ�����ڵ㣬������������
	for (int i = 0; i < nums.size(); i++) {
		TreeNode* node = NULL;
		if (nums[i] != -1) node = new TreeNode(nums[i]);		//������-1����null�����ڽ�null�ĳ�-1���漰����ȡ�ַ����Ĳ���
		vecTree[i] = node;		//���ڵ������Ӧ��vecTree��
		if (i == 0) root = node;
	}
	//��vecTree�еĽڵ㰴�ն��������ص����ӣ�Ҫע��ѭ��[����ֹ�������Լ��ڵ��Ĺ�ϵ
	for (int i = 0; i * 2 + 2 < vecTree.size(); i++) {
		if (vecTree[i] != NULL) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			vecTree[i]->right = vecTree[i * 2 + 2];
		}
	}
	return root;
}
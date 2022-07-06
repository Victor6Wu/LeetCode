#include"TreeNode.h"
#include<vector>
using namespace std;

//1.���ݸ�����vector����ƽ������������ض������ĸ��ڵ�
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

//2.����������
//������i�ĺ��Ӳ�һ������2i+1��2i+2��
TreeNode* deserialize(vector<int>& nums) {
	//�ȹ���һ������洢��ЩԪ��ת�ɵĽڵ�
	vector<TreeNode*> nodes;
	TreeNode* root = NULL;
	//���ݸ���ֵ�����ڵ㣬������������
	for (int i = 0; i < nums.size(); i++) {
		TreeNode* node = NULL;
		if (nums[i] != -1) node = new TreeNode(nums[i]);		//������-1����null�����ڽ�null�ĳ�-1���漰����ȡ�ַ����Ĳ���
		nodes[i] = node;		//���ڵ������Ӧ��vecTree��
		if (i == 0) root = node;
	}

    //�ع������������ӹ�ϵ����Ϊ�Ƕ�����������ƽ������������Զ��ڿսڵ�ü�¼һ�£�������ӽڵ��Ӧ��ϵ��λ������
    int count = 0; //��¼�սڵ�ĸ�����
    for (int i = 0; 2 * (i - count) + 2 <= nodes.size(); i++) {
        if (nodes[i] == nullptr) count++;
        else {
            nodes[i]->left = nodes[2 * (i - count) + 1];        //����ƽ���������˵��i�ڵ���ӽڵ���2i+1��2i+2��������Ϊ�Ƕ�������������м��пսڵ�����
            nodes[i]->right = nodes[2 * (i - count) + 2];
        }
    }
    return nodes[0];
}
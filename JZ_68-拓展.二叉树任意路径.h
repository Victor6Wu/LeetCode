//����һ���ڵ�ֵ���ظ��Ķ����������Ҹ��ڵ㵽����ָ���ڵ��·������Ŀ��ڵ�һ������
#include"TreeNode.h"
#include<vector>
using namespace std;

//�����ں�����������ж�Ŀ��ڵ����ĸ������ϣ�������̽��
//ȱ�������ж�Ŀ��ڵ��Ƿ���������Ҳ�Ǳ������㷨��ʱ�临�ӶȺܸ�O(N*k)
class Solution1 {
public:
	//�ж�Ŀ��ڵ����������
	bool isHere(TreeNode* root, TreeNode* des) {
		if (root == nullptr) return false;
		if (root == des) return true;
		return isHere(root->left, des) || isHere(root->right, des);
	}

	//���ĺ���
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

//�ݹ鷨��һ�α�����O(n)���ؼ�������Ҫһ��ֹͣ�����ı�־
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

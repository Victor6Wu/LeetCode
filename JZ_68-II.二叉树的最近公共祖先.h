//����һ��������, �ҵ�����������ָ���ڵ������������ȡ���һ���ڵ�Ҳ���������Լ������ȣ�
#include"TreeNode.h"
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//����1���Ա���룬��ȡ���ڵ㵽Ŀ��ڵ��·�����Ƚ�����·��
//��ȡ·����JZ_68-��չ
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

//����2���ݹ鷨�������ⲻ�Ϸֽ⣬�ٴ��¶��Ϲ鲢������ڹ�����Ѱ������Ĺ�������
//˼·������һ����root���������ڵ�p��q���������ڵ����ͬʱ��root�������������������ϣ�Ҳ�п��ܷ�ɢ�����������ϣ���������һ������root
//����ܹ�ȷ��q��p�Ƿ�ɢ�����������ϵģ���ô��ǰ��root����һ���������ȣ���һ����������Ǹ���Ҳ�п���root����p��q�е�һ��
//�ڵݹ�Ĺ����У�ֻ�����һ�θ�������������ȵ����
class Solution2 {
public:
	TreeNode* ans;
	//�ݹ麯�����ж�root�����Ƿ���p����q
	bool core(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return false;
		bool lson = core(root->left, p, q);  //�������Ƿ���p��q
		bool rson = core(root->right, p, q); //�������Ƿ���p��q
		//��������������������жϵ�ǰ�ڵ��Ƿ�Ϊ����Ĺ�������
		//���������1��p��q��ɢ������������2.p��һ��������qΪroot��3.q��һ��������pΪroot
		if ((lson && rson) || (lson || rson) && (root->val == p->val || root->val == q->val)) ans = root;
		return (lson || rson) || (root->val == p->val || root->val == q->val);	//������������������root��p��q
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		core(root, p, q);
		return ans;
	}
};

//����3����ɢ�б�洢�ӽڵ㵽���ڵ��ӳ��
//����p�����ϼ�¼���ڵ㣻�ٷ���q������Ѱ�Ҹ��ڵ�Ĺ������ж��Ƿ���p��������¼�г��ֹ�����һ�γ��ֵļ�Ϊ����Ĺ�������
class Solution2 {
private:
	unordered_map<TreeNode*, TreeNode*> father;
	unordered_map<TreeNode*, bool> visited;
public:
	//��������¼�Ӹ�ӳ��
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
		dfs(root);		//�����Ӹ�ӳ��
		while (p != nullptr) {	//��¼p��Ѱ������
			visited[p] = true;
			p = father[p];
		}
		while (q != nullptr) {	//q��Ѱ������
			if (visited[q]) return q;
			q = father[q];
		}
		return nullptr;
	}
};
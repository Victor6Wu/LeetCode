//��ʵ�������������ֱ��������л��ͷ����л���������
//ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ��
#include"TreeNode.h"
#include<queue>
#include<string>
#include<sstream>
using namespace std;

//�����˼·Ҳ�����ԣ����л��Ĺ��̣�����������Ľ����������������Ҫע�ⷵ��ֵ��string�����Һ��滹Ҫ�����У����Ա���Ҫ�ø���Ԫ�ؼ�������Ա��ں����ķ����л���
//�����л�����������ַ����Ƚ����У�������еĽڵ�Ԫ�أ��������ȱ���������Ȼ���������ڹ���ƽ��������ķ��������ڵ���������
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            //���ڿսڵ㣬����Ҫ��һ����Ǳ�־һ�£���Ϊ�������ؽ���������ʱ�򣬿սڵ���Ҫ��Ϊ�丸�ڵ�ĺ��ӳ��ֵ�
            if (!node) {
                ans += "*,";            //��*��ʾ�գ����ŷָ�
            }
            else {
                ans += to_string(node->val) + ",";  //���ŷָ�s
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        stringstream ss(data);
        string node;
        //���ַ������л�ȡ�ڵ㣬����������
        while (getline(ss, node, ',')) {
            if (node == "*") {
                nodes.push_back(nullptr);
            }
            else {
                TreeNode* tmp_node = new TreeNode(stoi(node));
                nodes.push_back(tmp_node);
            }
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
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
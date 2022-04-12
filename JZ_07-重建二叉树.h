//���ݸ�����ǰ���������������Ľ������������������������ڵ�
#include"TreeNode.h"
#include<vector>
using namespace std;

//�Ա���룬����ǰ����������������һ�����ڵ�ķֲ�������еݹ�
//ǰ�������ͷһ��Ԫ�ؿ϶���һ�����ġ��������������������ڵ�+�������ڵ�
//����������������ֳ����������֣��ֱ����������ڵ���������ڵ�
class Solution1 {
public:
    //root_index��ʾ��ǰ��ѯ��Χ�ڣ��������ĸ��ڵ㣻low��high��ʾ��������еĲ�ѯ��Χ
    TreeNode* buildCore(vector<int>& preorder, vector<int>& inorder, int root_index, int low, int high) {
        if (low > high) return nullptr;
        TreeNode* tmp_root = new TreeNode(preorder[root_index]);        //����һ�����ڵ�

        int tmp_index = low;      //�������Ľڵ�����ʼֵ
        //ѭ���ҵ����ڵ�����������е�λ��
        while (tmp_index <= high && preorder[root_index] != inorder[tmp_index]) {
            tmp_index++;
        }
        //���ݷֲ���ϵ�������Ƴ�ǰ������У��������Ӻ��Һ��ӵ����������������ڵ�����������еķ�Χ
        TreeNode* leftNode = buildCore(preorder, inorder, root_index + 1, low, tmp_index - 1);
        TreeNode* rightNode = buildCore(preorder, inorder, root_index + tmp_index - low + 1, tmp_index + 1, high);
        tmp_root->left = leftNode;
        tmp_root->right = rightNode;
        return tmp_root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildCore(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};

//�����µ�����ռ䣬�����˵�������
class Solution2 {
public:
    TreeNode* buildTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0) {                    //���Ϊ�գ�����NULL
            return NULL;
        }
        //������ǰ�������������ǰ�����������������������������������������
        vector<int> left_pre, right_pre, left_vin, right_vin;
        //ǰ�������һ���ڵ�һ��Ϊ���ڵ�
        TreeNode* head = new TreeNode(pre[0]);
        //�ҵ���������ĸ��ڵ�
        int root = 0;
        //�����ҵ�����������ڵ�����ֵ
        for (int i = 0; i < pre.size(); i++) {
            if (pre[0] == vin[i]) {
                root = i;
                break;
            }
        }
        //������������ĸ��ڵ㣬�Զ������ڵ���й鲢
        for (int i = 0; i < root; i++) {
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i + 1]);            //ǰ�������һ��Ϊ���ڵ�
        }

        for (int i = root + 1; i < pre.size(); i++) {
            right_vin.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }

        //�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
        head->left = buildTree(left_pre, left_vin);
        head->right = buildTree(right_pre, right_vin);
        return head;
    }
};
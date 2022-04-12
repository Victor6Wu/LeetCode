//请实现两个函数，分别用来序列化和反序列化二叉树。
//只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
#include"TreeNode.h"
#include<queue>
#include<string>
#include<sstream>
using namespace std;

//本题的思路也很明显，序列化的过程：将层序遍历的结果保存起来，但是要注意返回值是string，而且后面还要解序列，所以必须要让各个元素间隔开，以便于后续的反序列化；
//反序列化：将输入的字符串先解序列，获得所有的节点元素，用数组先保存起来，然后按照类似于构建平衡二叉树的方法，将节点连接起来
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
            //对于空节点，必须要用一个标记标志一下，因为后续在重建二叉树的时候，空节点是要作为其父节点的孩子出现的
            if (!node) {
                ans += "*,";            //用*表示空，逗号分隔
            }
            else {
                ans += to_string(node->val) + ",";  //逗号分隔s
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
        //从字符串序列获取节点，并存入数组
        while (getline(ss, node, ',')) {
            if (node == "*") {
                nodes.push_back(nullptr);
            }
            else {
                TreeNode* tmp_node = new TreeNode(stoi(node));
                nodes.push_back(tmp_node);
            }
        }
        //重构二叉树的连接关系，因为是二叉树，不是平衡二叉树，所以对于空节点得记录一下，解决父子节点对应关系移位的问题
        int count = 0; //记录空节点的个数，
        for (int i = 0; 2 * (i - count) + 2 <= nodes.size(); i++) {
            if (nodes[i] == nullptr) count++;
            else {
                nodes[i]->left = nodes[2 * (i - count) + 1];        //对于平衡二叉树来说，i节点的子节点是2i+1和2i+2，但是因为是二叉树，会出现中间有空节点的情况
                nodes[i]->right = nodes[2 * (i - count) + 2];
            }
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
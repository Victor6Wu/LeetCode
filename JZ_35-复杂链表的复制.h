//��ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬
//����һ�� random ָ��ָ�������е�����ڵ���� null��
#include<unordered_map>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

//����1���ݹ�+map
class Solution1 {
private:
    unordered_map<Node*, Node*> cacheNodes; //���ڼ�¼��ǰ��head�Ƿ��Ѿ������ƹ���key��ʾ�����������еĽڵ㣬value��ʾ��������Ľڵ�
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cacheNodes.count(head)) {
            Node* newhead = new Node(head->val);
            cacheNodes[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return cacheNodes[head];
    }
};

//����2������+�ڵ��֣����α�����
//��һ�α�������ÿ���ڵ�A����һ���ڵ�A'������ֱ�ӽ���A�ĺ��棬�г�A-A'-B-B'...���ֽṹ
//�ڶ��α����������µ�������ԭʼ�Ľڵ�A-B-C...��������������ص㣬�����Ľڵ�A'->random = A->random->next
//�����α������������ֳ�ԭʼ����͸����������ƽڵ���������
//ע��һ��nullptr�Ĵ���
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};
//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
//还有一个 random 指针指向链表中的任意节点或者 null。
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

//方法1：递归+map
class Solution1 {
private:
    unordered_map<Node*, Node*> cacheNodes; //用于记录当前的head是否已经被复制过，key表示被复制链表中的节点，value表示副本链表的节点
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

//方法2：迭代+节点拆分：三次遍历：
//第一次遍历：给每个节点A复制一个节点A'，并且直接接在A的后面，行程A-A'-B-B'...这种结构
//第二次遍历：遍历新的链表中原始的节点A-B-C...，根据新链表的特点，将其后的节点A'->random = A->random->next
//第三次遍历：将链表拆分成原始链表和复制链表，复制节点连接起来
//注意一下nullptr的处理
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
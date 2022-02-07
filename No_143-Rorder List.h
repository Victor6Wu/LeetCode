//You are given the head of a singly linked-list. The list can be represented as:L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
#include"ListNode.h"
#include<stack>
using namespace std;

//solution1：利用栈，将链表节点存入，这样就可以倒着取出后面的节点了
class Solution1 {
public:
	void reorderList(ListNode* head) {
		int n = 0;
		ListNode* next = head;
		stack<ListNode*> q;
		//计算节点数
		while (next != nullptr) {
			q.push(next);
			n++;
			next = next->next;
		}
		int half;
		if (n % 2 == 0) half = n / 2;
		else half = (n - 1) / 2;
		next = head;
		//先将后一半的节点交错插入前一半节点
		for (int i = 1; i <= half; i++) {
			ListNode* temp = next->next;
			next->next = q.top();
			q.pop();
			next = next->next;
			next->next = temp;
			next = next->next;
		}
		//将最后一个节点的next置为nullptr，无需考虑奇偶两种情况，因为上面的循环会是偶数情况的中间节点产生一个自循环
		next->next = nullptr;
	}
};

//solution2:借用数组，使得节点能够按索引访问
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr) {
			return;
		}
		vector<ListNode*> vec;
		ListNode* node = head;
		while (node != nullptr) {
			vec.emplace_back(node);
			node = node->next;
		}
		int i = 0, j = vec.size() - 1;
		while (i < j) {
			vec[i]->next = vec[j];
			i++;
			if (i == j) {
				break;
			}
			vec[j]->next = vec[i];
			j--;
		}
		vec[i]->next = nullptr;
	}
};

//solution3:寻找链表中间节点+链表逆序+合并链表
class Solution3 {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr) {
			return;
		}
		ListNode* mid = middleNode(head);
		ListNode* l1 = head;
		ListNode* l2 = mid->next;
		mid->next = nullptr;
		l2 = reverseList(l2);
		mergeList(l1, l2);
	}

	//快慢指针找到链表的中间节点
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	//翻转链表
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}

	//交叉合并两个链表，l1的节点数最多比l2多一个
	void mergeList(ListNode* l1, ListNode* l2) {
		ListNode* l1_tmp;
		ListNode* l2_tmp;
		while (l1_tmp != nullptr && l2_tmp != nullptr) {
			l1_tmp = l1->next;
			l2_tmp = l2->next;

			l1->next = l2;
			l1 = l1_tmp;

			l2->next = l1;
			l2 = l2_tmp;
		}
	}
};
//You are given the head of a singly linked-list:L0 �� L1 �� �� �� Ln - 1 �� Ln
//You are given the head of a singly linked-list:L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
#include"ListNode.h"
#include<stack>
using namespace std;

class Solution {
public:
	void reorderList(ListNode* head) {
		int n = 0;
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode* next = head;
		stack<ListNode*> q;
		while (next != nullptr) {
			q.push(next);
			n++;
			next = next->next;
		}
		int half;
		if (n % 2 == 0) half = n / 2;
		else half = (n - 1) / 2;
		for (int i = 1; i <= half; i++) {
			ListNode* temp = head->next;
			head->next = q.top();
			q.pop();
			head = head->next;
			head->next = temp;
			head = head->next;
		}
		if (n % 2 == 0) {
			head = nullptr;
		}
		else {
			head->next = nullptr;
		}
		head = dummy->next;
	}
};
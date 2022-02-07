//You are given the head of a singly linked-list. The list can be represented as:L0 �� L1 �� �� �� Ln - 1 �� Ln
//Reorder the list to be on the following form:L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
#include"ListNode.h"
#include<stack>
using namespace std;

//solution1������ջ��������ڵ���룬�����Ϳ��Ե���ȡ������Ľڵ���
class Solution1 {
public:
	void reorderList(ListNode* head) {
		int n = 0;
		ListNode* next = head;
		stack<ListNode*> q;
		//����ڵ���
		while (next != nullptr) {
			q.push(next);
			n++;
			next = next->next;
		}
		int half;
		if (n % 2 == 0) half = n / 2;
		else half = (n - 1) / 2;
		next = head;
		//�Ƚ���һ��Ľڵ㽻�����ǰһ��ڵ�
		for (int i = 1; i <= half; i++) {
			ListNode* temp = next->next;
			next->next = q.top();
			q.pop();
			next = next->next;
			next->next = temp;
			next = next->next;
		}
		//�����һ���ڵ��next��Ϊnullptr�����迼����ż�����������Ϊ�����ѭ������ż��������м�ڵ����һ����ѭ��
		next->next = nullptr;
	}
};

//solution2:�������飬ʹ�ýڵ��ܹ�����������
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

//solution3:Ѱ�������м�ڵ�+��������+�ϲ�����
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

	//����ָ���ҵ�������м�ڵ�
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	//��ת����
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

	//����ϲ���������l1�Ľڵ�������l2��һ��
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
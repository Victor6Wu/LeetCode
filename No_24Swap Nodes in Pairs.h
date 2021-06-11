//Given a linked list, swap every two adjacent nodes and return its head.
#include<iostream>
using namespace std;
#include"ListNode.h"

class Solution {
public:
	//solution 1: �ı�ڵ��е�val
	ListNode* swapPairs1(ListNode* head) {
		if (head == nullptr) return head;
		ListNode* origin = head;						//Ҫ����һ���ڵ�ָ�������head�ڵ㣬���head�ᷢ���ı䣬���ܷ���head
		ListNode* successor = nullptr;
		while (head != nullptr) {
			successor = head->next;
			if (successor == nullptr)
				break;
			int temp = head->val;
			head->val = successor->val;
			successor->val = temp;
			head = successor->next;
		}
		return origin;
	}

	//solution 2: ���װ汾�����ı�����ڵ�ֵ�����޸Ľڵ㱾��(���ǵ����汾��ֻ�Ǿ�����벻ͬ)
	ListNode* swapPairs2(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;	
		ListNode* dummy = new ListNode(0);								//���봴��һ��ͷ�ڵ��������ķ���
		ListNode* temp = dummy;											//����һ����ʱ�ڵ㣬���ڱ�ʾÿ��ѭ����ǰһ���ڵ㣬����ǰ������
		dummy->next = head->next;
		temp->next = head;
		while (head != nullptr && head->next != nullptr) {
			ListNode* successor = head->next;
			head->next = successor->next;
			successor->next = head;
			temp->next = successor;										//����Ҫ��֮ǰ�Ľ��������
			temp = head;
			head = head->next;
		}
		return dummy->next;
	}

	//solution 3: �ݹ�
	ListNode* swapPairs3(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return	head;
		}
		ListNode* newhead = head->next;
		head->next = swapPairs3(newhead->next);
		newhead->next = head;
		return newhead;
	}

	//solution 4������
	ListNode* swapPairs4(ListNode* head) {
		ListNode* dummy = new ListNode(0);										//�����ڱ��ڵ�
		dummy->next = head;
		ListNode* temp = dummy;													//�������ڱ��ڵ㿪ʼ��ѭ���ڵ�
		while (temp->next != nullptr && temp->next->next != nullptr) {
			ListNode* node1 = temp->next;
			ListNode* node2 = temp->next->next;
			temp->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			temp = node1;														//ÿ�θ��µĶ���Ϊtemp
		}
		return dummy->next;
	}
};


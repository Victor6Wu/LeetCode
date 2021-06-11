//Given a linked list, swap every two adjacent nodes and return its head.
#include<iostream>
using namespace std;
#include"ListNode.h"

class Solution {
public:
	//solution 1: 改变节点中的val
	ListNode* swapPairs1(ListNode* head) {
		if (head == nullptr) return head;
		ListNode* origin = head;						//要创建一个节点指向最初的head节点，最后head会发生改变，不能返回head
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

	//solution 2: 进阶版本，不改变链表节点值，仅修改节点本身(就是迭代版本，只是具体代码不同)
	ListNode* swapPairs2(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;	
		ListNode* dummy = new ListNode(0);								//必须创建一个头节点用于最后的返回
		ListNode* temp = dummy;											//必须一个临时节点，用于表示每次循环的前一个节点，用于前后连接
		dummy->next = head->next;
		temp->next = head;
		while (head != nullptr && head->next != nullptr) {
			ListNode* successor = head->next;
			head->next = successor->next;
			successor->next = head;
			temp->next = successor;										//必须要跟之前的结果连接上
			temp = head;
			head = head->next;
		}
		return dummy->next;
	}

	//solution 3: 递归
	ListNode* swapPairs3(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return	head;
		}
		ListNode* newhead = head->next;
		head->next = swapPairs3(newhead->next);
		newhead->next = head;
		return newhead;
	}

	//solution 4：迭代
	ListNode* swapPairs4(ListNode* head) {
		ListNode* dummy = new ListNode(0);										//构建哨兵节点
		dummy->next = head;
		ListNode* temp = dummy;													//构建从哨兵节点开始的循环节点
		while (temp->next != nullptr && temp->next->next != nullptr) {
			ListNode* node1 = temp->next;
			ListNode* node2 = temp->next->next;
			temp->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			temp = node1;														//每次更新的对象为temp
		}
		return dummy->next;
	}
};


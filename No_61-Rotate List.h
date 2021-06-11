// Given the head of a linked list, rotate the list to the right by k places.

#include"ListNode.h"
class Solution {
public:
	//solution 1:自编代码，利用移动次数和原本链表节点个数的关系，找到移动后将作为头节点的节点，断开其与前节点的链接，将原先尾节点与头节点链接
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) return head;
		//获取链表节点个数，以及找到尾节点
		int length = 1;
		ListNode* tail = head;
		while (tail->next != nullptr) {
			++length;
			tail = tail->next;
		}

		k = k % length;		//真实移动位置
		if (k == 0) return head;			//刚好转一圈，则不需要移动


		ListNode* newHead = nullptr;				//用于指向最后的新的头节点
		ListNode* temp = head;						//临时指针，用于指向新头节点前一个节点
		for (int i = 1; i < length - k; ++i) {		//此处i一定是从1开始，这样会使得temp指向新头节点的前一个节点
			temp = temp->next;
		}
		//修改新头节点与前节点的连接关系，连接原始尾节点和头节点的连接
		newHead = temp->next;
		temp->next = nullptr;
		tail->next = head;			//使原先的尾节点与原先的头节点衔接

		return newHead;
	}
	//solution 2:思路同1，都是想办法找到新头节点的前一个节点，采用快慢指针，快指针先行，后同行直至快指针抵达末尾，此时慢指针即为新头节点前一个节点

};
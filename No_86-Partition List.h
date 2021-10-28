//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
#include"ListNode.h"
using namespace std;

//solution 1：采用额外的链表，空间复杂度O(1)，时间复杂度O(N)
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		// 构建连个链表
		ListNode* dummy1 = new ListNode(0);
		ListNode* dummy2 = new ListNode(0);
		ListNode* nex1 = dummy1;
		ListNode* nex2 = dummy2;
		while (head != nullptr) {
			if (head->val < x) {
				nex1->next = head;
				nex1 = nex1->next;
				head = head->next;
			}
			else {
				nex2->next = head;
				nex2 = nex2->next;
				head = head->next;
			}
		}
		// 汇总结果
		nex1->next = dummy2->next;	//	小链表的结尾和大链表的头节点连接
		nex2->next = nullptr;		//	大链表的结尾最后接一个空指针
		return dummy1->next;
	}
};

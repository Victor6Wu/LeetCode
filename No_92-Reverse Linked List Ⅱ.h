//Given the head of a singly linked list and two integers left and right where left <= right, 
//reverse the nodes of the list from position left to position right, and return the reversed list.
#include"ListNode.h"
using namespace std;

class Solution1 {	//solution 1:借鉴No25，先找到待翻转区间两头的节点，翻转后跟前后衔接，时间复杂度 2*O(N)
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* leftNode = nullptr;
		ListNode* rightNode = nullptr;
		ListNode* hair = nullptr;

		ListNode* temp = dummy;
		int count = 0;
		while (temp->next != nullptr) {
			if (count == left - 1) {
				hair = temp;
			}
			temp = temp->next;
			count++;
			if (count == left) {
				leftNode = temp;
			}
			if (count == right) {
				rightNode = temp;
				break;
			}
		}
		ListNode* prev = rightNode->next;	//设置倒置所用的前驱节点，即right右侧的节点
		while (prev != rightNode) {
			ListNode* nex = leftNode->next;
			leftNode->next = prev;
			prev = leftNode;
			leftNode = nex;
		}
		//这个地方注意：
		hair->next = prev;

		return dummy->next;
	}
};

class Solution2 {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;	
		//先找到left的前一个节点
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode* curr = pre->next;
		ListNode* nex;
		for (int i = 0; i < right - left; i++) {
			nex = curr->next;	//nex为每次实际翻转的节点
			curr->next = nex->next;	//curr跳过nex，连接nex的后一个节点
			nex->next = pre->next;	//将nex连在翻转区的开头，即pre所直接连接的节点
			pre->next = nex;		//成功将nex移动，处于当前已经完成翻转的节点的第一个，即与pre直接连接的节点
		}	
		return dummy->next;
	}
};
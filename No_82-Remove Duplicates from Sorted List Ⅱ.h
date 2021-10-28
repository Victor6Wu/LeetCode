//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//Return the linked list sorted as well.
#include"ListNode.h"
using namespace std;

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode();
		ListNode* prev = dummy;
		int val;
		while (head != nullptr) {
			val = head->val;
			// 满足后面的节点与当前节点不等，就可以进行连接并且后移了
			if (head->next == nullptr || head->next->val != val) {
				prev->next = head;
				prev = head;
				head = head->next;
			}
			else {
				head = head->next;
				// 一直向后找不等的节点，或者空节点
				while (head != nullptr && head->val == val) {
					head = head->next;
				}
				// 如果最后找到的是空节点，说明head已经跑到末尾，可以直接连接；如果只是找到不等的节点，不能连接，必须判断其后是否是重复的节点
				if (head == nullptr) {
					prev->next = head;
				}
			}
		}
		return dummy->next;
	}
};
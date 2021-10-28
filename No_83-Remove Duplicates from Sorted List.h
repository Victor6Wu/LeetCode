//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
#include "ListNode.h"
using namespace std;

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* nodeFirst = head;
		ListNode* nodeSecond= head;
		while (nodeFirst != nullptr) {
			nodeSecond = nodeFirst->next;
			while (nodeSecond != nullptr && nodeSecond->val == nodeFirst->val) {
				nodeSecond = nodeSecond->next;
			}
			nodeFirst->next = nodeSecond;		//�����м���ȵĽڵ㣬��first���µ�second�ν�
			nodeFirst = nodeSecond;
		}
		return head;
	}
};
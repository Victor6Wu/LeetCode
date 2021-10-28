//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
#include"ListNode.h"
using namespace std;

//solution 1�����ö���������ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		// ������������
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
		// ���ܽ��
		nex1->next = dummy2->next;	//	С����Ľ�β�ʹ������ͷ�ڵ�����
		nex2->next = nullptr;		//	������Ľ�β����һ����ָ��
		return dummy1->next;
	}
};

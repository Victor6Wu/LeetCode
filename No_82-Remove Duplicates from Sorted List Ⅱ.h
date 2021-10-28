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
			// �������Ľڵ��뵱ǰ�ڵ㲻�ȣ��Ϳ��Խ������Ӳ��Һ�����
			if (head->next == nullptr || head->next->val != val) {
				prev->next = head;
				prev = head;
				head = head->next;
			}
			else {
				head = head->next;
				// һֱ����Ҳ��ȵĽڵ㣬���߿սڵ�
				while (head != nullptr && head->val == val) {
					head = head->next;
				}
				// �������ҵ����ǿսڵ㣬˵��head�Ѿ��ܵ�ĩβ������ֱ�����ӣ����ֻ���ҵ����ȵĽڵ㣬�������ӣ������ж�����Ƿ����ظ��Ľڵ�
				if (head == nullptr) {
					prev->next = head;
				}
			}
		}
		return dummy->next;
	}
};
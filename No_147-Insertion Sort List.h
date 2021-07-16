//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
#include"ListNode.h"
using namespace std;

class Solution {
public:
	//solution 1:�Ա���룬���������ǰ���룬�ص���ע��Ҫ����Ľڵ������λ�õ�ǰ���νӣ��Լ��뿪����ǰ���ν�
	//ʱ�临�Ӷ�O(n^2)
	ListNode* insertionSortList1(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		//����һ���ڱ��ڵ�
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		//�������ڵ����Ľڵ�
		ListNode* next_node = head;			//next_node��head��ʼ������ÿ�����������жϵĽڵ������һ���ڵ㣬������������Ҫ����Ľڵ��뿪���ܹ�ǰ���ν�����
		while (next_node->next != nullptr) {
			ListNode* compare = dummy;
			bool signal = false;
			while (compare->next != next_node->next) {
				if (compare->next->val <= next_node->next->val) {
					compare = compare->next;
				}
				else {

					ListNode* copy = next_node->next;		//����һ��next_node->next�ĸ������ڲ���ǰ�������������next������Ҫ����������
					next_node->next = next_node->next->next;	//��next_node�뿪��λ�������ν�
					signal = true;
					//����next�ĸ���
					copy->next = compare->next;				//���ڵ���룬����ǰ���ν�
					compare->next = copy;
					break;
				}
			}
			if (signal == false) {
				next_node = next_node->next;		//�����ڴ˴����Խ��compare->next == next�����
			}
		}
		return dummy->next;
	}

	//solution 2:�����Ż�
	ListNode* insertionSortList2(ListNode* head) {
		//����ͷ���ƽڵ�
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		//��ʵcur��rightʼ���ǽ��ڵ�
		ListNode* cur = head;		//��ʾ�Լ�����Ĳ��ֵ����һ���ڵ�
		ListNode* right = head->next;		//���ڲ���Ľڵ�

		while (cur && cur->next) {
			//���ж�right�ڵ��Ƿ����ô���cur������ǣ�����߾�����һλ����
			if (cur->val <= right->val) {
				cur = cur->next;
			}
			//����Ҫ��ǰ���Ƚϴ�С
			else {
				ListNode* pre = dummy;
				while (pre->next->val <= right->val) {		//������sln1ǿ������ͬ����ǰ���Ƚϵ�ʱ��Ҫ��next
					pre = pre->next;
				}
				cur->next = right->next;		//right��Ҫ�뿪������Ҫ���뿪����ǰ��ڵ��ν�
				right->next = pre->next;		//right�����λ��pre��next���ν�
				pre->next = right;				//right�����λ��pre���ν�
			}
			right = cur->next;				//���²���ڵ�right
		}
		return dummy->next;
	}
};
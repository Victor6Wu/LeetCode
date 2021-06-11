// Given the head of a linked list, rotate the list to the right by k places.

#include"ListNode.h"
class Solution {
public:
	//solution 1:�Ա���룬�����ƶ�������ԭ������ڵ�����Ĺ�ϵ���ҵ��ƶ�����Ϊͷ�ڵ�Ľڵ㣬�Ͽ�����ǰ�ڵ�����ӣ���ԭ��β�ڵ���ͷ�ڵ�����
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) return head;
		//��ȡ����ڵ�������Լ��ҵ�β�ڵ�
		int length = 1;
		ListNode* tail = head;
		while (tail->next != nullptr) {
			++length;
			tail = tail->next;
		}

		k = k % length;		//��ʵ�ƶ�λ��
		if (k == 0) return head;			//�պ�תһȦ������Ҫ�ƶ�


		ListNode* newHead = nullptr;				//����ָ�������µ�ͷ�ڵ�
		ListNode* temp = head;						//��ʱָ�룬����ָ����ͷ�ڵ�ǰһ���ڵ�
		for (int i = 1; i < length - k; ++i) {		//�˴�iһ���Ǵ�1��ʼ��������ʹ��tempָ����ͷ�ڵ��ǰһ���ڵ�
			temp = temp->next;
		}
		//�޸���ͷ�ڵ���ǰ�ڵ�����ӹ�ϵ������ԭʼβ�ڵ��ͷ�ڵ������
		newHead = temp->next;
		temp->next = nullptr;
		tail->next = head;			//ʹԭ�ȵ�β�ڵ���ԭ�ȵ�ͷ�ڵ��ν�

		return newHead;
	}
	//solution 2:˼·ͬ1��������취�ҵ���ͷ�ڵ��ǰһ���ڵ㣬���ÿ���ָ�룬��ָ�����У���ͬ��ֱ����ָ��ִ�ĩβ����ʱ��ָ�뼴Ϊ��ͷ�ڵ�ǰһ���ڵ�

};
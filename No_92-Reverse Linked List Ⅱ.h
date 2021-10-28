//Given the head of a singly linked list and two integers left and right where left <= right, 
//reverse the nodes of the list from position left to position right, and return the reversed list.
#include"ListNode.h"
using namespace std;

class Solution1 {	//solution 1:���No25�����ҵ�����ת������ͷ�Ľڵ㣬��ת���ǰ���νӣ�ʱ�临�Ӷ� 2*O(N)
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
		ListNode* prev = rightNode->next;	//���õ������õ�ǰ���ڵ㣬��right�Ҳ�Ľڵ�
		while (prev != rightNode) {
			ListNode* nex = leftNode->next;
			leftNode->next = prev;
			prev = leftNode;
			leftNode = nex;
		}
		//����ط�ע�⣺
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
		//���ҵ�left��ǰһ���ڵ�
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode* curr = pre->next;
		ListNode* nex;
		for (int i = 0; i < right - left; i++) {
			nex = curr->next;	//nexΪÿ��ʵ�ʷ�ת�Ľڵ�
			curr->next = nex->next;	//curr����nex������nex�ĺ�һ���ڵ�
			nex->next = pre->next;	//��nex���ڷ�ת���Ŀ�ͷ����pre��ֱ�����ӵĽڵ�
			pre->next = nex;		//�ɹ���nex�ƶ������ڵ�ǰ�Ѿ���ɷ�ת�Ľڵ�ĵ�һ��������preֱ�����ӵĽڵ�
		}	
		return dummy->next;
	}
};
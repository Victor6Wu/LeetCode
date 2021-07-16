//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
#include"ListNode.h"
using namespace std;

class Solution {
public:
	//solution 1:自编代码，逐个考虑向前插入，重点是注意要插入的节点与插入位置的前后衔接，以及离开处的前后衔接
	//时间复杂度O(n^2)
	ListNode* insertionSortList1(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		//构造一个哨兵节点
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		//构造用于迭代的节点
		ListNode* next_node = head;			//next_node从head开始，但是每次真正用于判断的节点是其后一个节点，这样做有利于要插入的节点离开后，能够前后衔接链表
		while (next_node->next != nullptr) {
			ListNode* compare = dummy;
			bool signal = false;
			while (compare->next != next_node->next) {
				if (compare->next->val <= next_node->next->val) {
					compare = compare->next;
				}
				else {

					ListNode* copy = next_node->next;		//创建一个next_node->next的副本用于插入前面的有序链表，而next本身需要继续向后迭代
					next_node->next = next_node->next->next;	//将next_node离开的位置重新衔接
					signal = true;
					//插入next的副本
					copy->next = compare->next;				//将节点插入，并与前后衔接
					compare->next = copy;
					break;
				}
			}
			if (signal == false) {
				next_node = next_node->next;		//这句放在此处可以解决compare->next == next的情况
			}
		}
		return dummy->next;
	}

	//solution 2:代码优化
	ListNode* insertionSortList2(ListNode* head) {
		//创建头部哑节点
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		//其实cur与right始终是紧邻的
		ListNode* cur = head;		//表示以及排序的部分的最后一个节点
		ListNode* right = head->next;		//用于插入的节点

		while (cur && cur->next) {
			//先判断right节点是否正好大于cur，如果是，则二者均后移一位即可
			if (cur->val <= right->val) {
				cur = cur->next;
			}
			//否则，要从前向后比较大小
			else {
				ListNode* pre = dummy;
				while (pre->next->val <= right->val) {		//这里与sln1强调的相同，从前向后比较的时候要用next
					pre = pre->next;
				}
				cur->next = right->next;		//right将要离开，所以要将离开处的前后节点衔接
				right->next = pre->next;		//right与插入位置pre的next相衔接
				pre->next = right;				//right与插入位置pre相衔接
			}
			right = cur->next;				//更新插入节点right
		}
		return dummy->next;
	}
};
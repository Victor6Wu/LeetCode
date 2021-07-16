//Given the head of a linked list, return the list after sorting it in ascending order.
//Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

#include"ListNode.h";
using namespace std;

class Solution {
public:
	//solution 1：归并排序，自顶向下的递归方法
	ListNode* sortList1(ListNode* head) {
		return sortList_fuc(head, nullptr);
	}
	//真正用于递归的函数
	//此时输入的每个链表是用head与tail表示的,且属于左闭右开型[head:tail)
	ListNode* sortList_fuc(ListNode* head, ListNode* tail) {	
		if (head == nullptr) {				
			return head;
		}
		if (head->next == tail) {		//表示只有一个节点的链表
			head->next = nullptr;		//这一步很重要，将节点从原始的链表中独立出来，并赋予其自己的“tail”
			return head;
		}
		ListNode* fast = head, * slow = head;		//用快慢指针的方法找到中间节点
		while (fast != tail) {
			fast = fast->next;
			slow = slow->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
		ListNode* mid = slow;
		return merge(sortList_fuc(head, mid), sortList_fuc(mid, tail));
	}

	//合并两个有序链表
	ListNode* merge(ListNode* head1, ListNode* head2) {	//注意此处输入两个链表是用两个head表示的，没给出tail
		ListNode* dummy = new ListNode(0);		//哨兵节点
		ListNode* temp = dummy;		//哨兵节点的copy，用于指向新链表的最后一个节点，用于在其后增加新节点
		while (head1 != nullptr && head2 != nullptr) {
			if (head1->val <= head2->val) {
				temp->next = head1;
				head1 = head1->next;
			}
			else
			{
				temp->next = head2;
				head2 = head2->next;
			}
			temp = temp->next;
		}
		if (head1 != nullptr) {
			temp->next = head1;
		}
		else if (head2 != nullptr) {
			temp->next = head2;
		}
		return dummy->next;
	}

	//solution 2：归并排序，自底向上的迭代方法,子链长度由1逐渐翻倍，归并的时候仍然是用merge函数
	ListNode* sortList2(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		int length = 0;
		ListNode* node = head;
		while (node != nullptr) {
			length++;
			node = node->next;
		}
		ListNode* dummy = new ListNode(0, head);
		for (int sublength = 1; sublength < length; sublength <<= 1) {		//注意子链长度大于等于链表长度时循环结束
			ListNode* prev = dummy;			//每两个子链拼接后要与前面拼接好的链表衔接，pre表示已排序链表的尾节点
											//且prev在每次for循环时都会重新定义，用于不同的sublength
			ListNode* curr = dummy->next;	//每次for循环下都有curr用于从前向后遍历所有的节点
			while (curr != nullptr) {
				ListNode* head1 = curr;		//创建用于合并的第一个子链表的head
				//根据子链的长度向后找到子链的尾节点，值得注意的是子链的长度是可能达不到sublength的
				for (int i = 1; i < sublength && curr->next != nullptr; i++) {
					curr = curr->next;
				}
				ListNode* head2 = curr->next;		//第二个子链的head，哪怕是nullptr也要创建
				curr->next = nullptr;			//以nullptr来结束head1子链的末尾
				curr = head2;					//将curr指向head2，继续向后查找

				//开始给head2子链寻找结尾
				//这里要注意，比head1的循环多了一个条件，因为此时head2本身就可能是nullptr
				for (int i = 1; i < sublength && curr != nullptr && curr->next != nullptr; i++) {
					curr = curr->next;
				}

				//给head2子链结尾，且考虑是否要构建一个临时的指针节点，用于head2结尾后让curr能继续向后遍历
				ListNode* temp = nullptr;
				if (curr != nullptr) {		//表明head2子链不是空
					temp = curr->next;		//用于下一对子链归并
					curr->next = nullptr;		//结束子链2
				}
				curr = temp;				//此时的curr指向head2子链尾节点后的位置，用于继续向后遍历

				ListNode* merged = merge(head1, head2);
				prev->next = merged;		//将归并好的子链衔接到前面归并好的子链
				//跟新prev为以归并链表的尾节点
				while (prev->next != nullptr) {
					prev = prev->next;
				}
			}
		}
		return dummy->next;
	}
};
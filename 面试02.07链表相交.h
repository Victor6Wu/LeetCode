//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
//注意，这里相交指的是“节点相同”，不是节点的值相等
#include"ListNode.h"
#include<unordered_set>
using namespace std;

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while (curr1 != nullptr) {
            lenA++;
            curr1 = curr1->next;
        }
        while (curr2 != nullptr) {
            lenB++;
            curr2 = curr2->next;
        }

        curr1 = headA;
        curr2 = headB;
        //始终让A表示长的链表，这样不用重复代码，但是要注意，题目要求不能改变两个链表的结构
        //curr1在长链表上遍历，curr2在短链表上遍历
        if (lenB > lenA) {
            swap(curr1, curr2);
            swap(lenA, lenB);
        }
        //对齐链表尾部
        int gap = lenA - lenB;
        while (gap > 0) {
            curr1 = curr1->next;
            gap--;
        }
        while (curr1 != nullptr) {
            if (curr1 == curr2) {          //节点相同，而非值相等
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return nullptr;
    }
};
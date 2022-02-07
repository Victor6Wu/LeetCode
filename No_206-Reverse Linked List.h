//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;       //前驱结点
        ListNode* temp;
        while (head != nullptr) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
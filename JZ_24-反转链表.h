//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};
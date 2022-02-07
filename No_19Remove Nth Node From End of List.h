#include"ListNode.h"

class Solution {
public:
//solution 1:
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        if (head == nullptr) {                  //要提前判断给的链表为空的情况
        return head;
        }
        ListNode* faster = head;
        ListNode* slower = head;

        while (n > 0) {                        //如果此处必须是 > 0，下面的循环条件： faster-next != nullptr;
            faster = faster->next;
            n--;
        }
        if (faster == nullptr)                  //还要考虑删除的是不是头节点
            return head->next;
        while (faster->next != nullptr) {
            faster = faster->next;
            slower = slower->next;
        }
        slower->next = slower->next->next;
        return head;
    }

 //solution 2:
 ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);                //人为引入一个节点在head前，避免了solution 1 中的链表为空；删除节点为头节点的情况
        dummy->next = head;
        ListNode* fast = dummy, * slow = dummy;
        for(int i = 0; i <= n; ++i)                       //会移动 n+1 次,因为想让慢指针落到被删除结点的前一个
        fast = fast->next;

        while (fast) {                                    //删除头节点的情况也被直接判断，若删除的为头节点，此时fast已经为nullptr
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
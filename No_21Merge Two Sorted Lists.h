#include"ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l2->val < l1->val) {
                    tail->next = l2;
                    l2 = l2->next;
                    tail = tail->next;
                }
                else
                {
                    tail->next = l1;
                    l1 = l1->next;
                    tail = tail->next;
                }
                continue;                                       //此处是continue，不是break
            }
            if (l2 == nullptr) {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        return dummy->next;
    }
};
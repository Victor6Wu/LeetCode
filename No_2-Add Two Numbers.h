#include"ListNode.h"

class Solution {
public:
    //solution 1:   
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;  //�˴���head��tail��ʾ���ս���ĵ�һ�������һ��ListNode*��������List�е�header��tailer��
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);   //���head��tailָ��ͬһ��ListNode��
            }
            else {
                tail->next = new ListNode(sum % 10);    //֮����ǲ��ϸ���tail��
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);           //��֤��������һ����λ��ҲҪ�����µ�ListNode
        }
        return head;
    }

    //solution 2:   
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        int carry = 0;
        int value = 0;
        ListNode* prev = &dummy;
        for (;
            l1 != nullptr || l2 != nullptr;
            l1 = l1 == nullptr ? nullptr : l1->next,
            l2 = l2 == nullptr ? nullptr : l2->next,
            prev = prev->next) {
            int n1 = l1 == nullptr ? 0 : l1->val;
            int n2 = l2 == nullptr ? 0 : l2->val;
            value = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            prev->next = new ListNode(value);
        }
        if (carry > 0) {
            prev->next = new ListNode(value);
        }
        return dummy.next;
    }
};

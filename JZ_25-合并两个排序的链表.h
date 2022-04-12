//����������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�
#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        while (l1) {
            tmp->next = l1;
            l1 = l1->next;
            tmp = tmp->next;
        }
        while (l2) {
            tmp->next = l2;
            l2 = l2->next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
};
//输入一个链表，输出该链表中倒数第k个节点。
#include"ListNode.h"
using namespace std;

//快慢指针法
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && k-- > 0) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
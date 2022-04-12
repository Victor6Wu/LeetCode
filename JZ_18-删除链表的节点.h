//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//返回删除后的链表的头节点。
#include"ListNode.h"
using namespace std;


//单指针足以满足需要，双指针也可
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre->next != nullptr) {
            if (pre->next->val == val) {
                pre->next = pre->next->next;
                break;
            }
            pre = pre->next;
        }
        return dummy->next;
    }
};
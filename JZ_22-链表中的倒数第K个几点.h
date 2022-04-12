//����һ����������������е�����k���ڵ㡣
#include"ListNode.h"
using namespace std;

//����ָ�뷨
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
//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//����ɾ����������ͷ�ڵ㡣
#include"ListNode.h"
using namespace std;


//��ָ������������Ҫ��˫ָ��Ҳ��
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
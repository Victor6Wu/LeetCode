#include"ListNode.h"

class Solution {
public:
//solution 1:
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        if (head == nullptr) {                  //Ҫ��ǰ�жϸ�������Ϊ�յ����
        return head;
        }
        ListNode* faster = head;
        ListNode* slower = head;

        while (n > 0) {                        //����˴������� > 0�������ѭ�������� faster-next != nullptr;
            faster = faster->next;
            n--;
        }
        if (faster == nullptr)                  //��Ҫ����ɾ�����ǲ���ͷ�ڵ�
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
        ListNode* dummy = new ListNode(0);                //��Ϊ����һ���ڵ���headǰ��������solution 1 �е�����Ϊ�գ�ɾ���ڵ�Ϊͷ�ڵ�����
        dummy->next = head;
        ListNode* fast = dummy, * slow = dummy;
        for(int i = 0; i <= n; ++i)                       //���ƶ� n+1 ��,��Ϊ������ָ���䵽��ɾ������ǰһ��
        fast = fast->next;

        while (fast) {                                    //ɾ��ͷ�ڵ�����Ҳ��ֱ���жϣ���ɾ����Ϊͷ�ڵ㣬��ʱfast�Ѿ�Ϊnullptr
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;       //ǰ�����
        ListNode* temp;
        while (head != nullptr) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
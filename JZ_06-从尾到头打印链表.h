//����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
#include<vector>
#include"ListNode.h"
using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        vector<int> res;
        while (pre != nullptr) {
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};
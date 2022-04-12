//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
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
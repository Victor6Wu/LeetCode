//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
#include<unordered_set>
#include"ListNode.h"
using namespace std;

//方法1：借用set存储经过的节点
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> table;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (table.find(cur) != table.end()) {
                return cur;
            }
            table.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};

//方法2：快慢指针+数学分析。经过分析，有一个重要的结论：
//从头结点出发一个指针，从相遇节点也出发一个指针，这两个指针每次只走一个节点，那么当这两个指针相遇的时候就是环形入口的节点。
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};
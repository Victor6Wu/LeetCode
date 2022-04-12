//给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。
//对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 。
//返回修改后链表的头节点 head 。
#include"ListNode.h"
using namespace std;

//节点值为0的节点作为最后链表的节点，把其后的节点，一直到下一个零节点为止的节点值加入该0，然后建立连接，均向后移动一位
//主要是注意最后循环怎么终止，怎么让最后一个节点别和0节点连接
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 != nullptr) {
            while (p2->val != 0) {
                p1->val += p2->val;
                p2 = p2->next;
            }
            if (p2->next != nullptr) {
                p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
            else {
                p1->next = nullptr;
                p2 = p2->next;
            }
        }
        return head;
    }
};

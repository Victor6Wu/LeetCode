using namespace std;
#include<queue>
#include<vector>
#include"ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        int carry = 0;
        int value = 0;
        ListNode* prev = &dummy;
        for (;
            l1 != nullptr || l2 != nullptr;
            l1 = l1 == nullptr ? nullptr : l1->next,
            l2 = l2 == nullptr ? nullptr : l2->next,
            prev = prev->next) {
            int n1 = l1 == nullptr ? 0 : l1->val;
            int n2 = l2 == nullptr ? 0 : l2->val;
            value = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            prev->next = new ListNode(value);
        }
        if (carry > 0) {
            prev->next = new ListNode(value);
        }
        return dummy.next;
    }

    //solution 1：顺序合并，构建一个空链表，循环将vector中的链表与其做2合并
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        for (auto i : lists) {
            head = mergeTwoLists(head, i);
        }
        return head;
    }

    //solution 2：分治法，不断地两两合并，如0和1、2和3、...、再0和2、4和6、...
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        int m = 1, n = 2;
        int k = lists.size();
        if (k == 0)
            return nullptr;
        while (m < k) {
            for (int i = 0; i < k; i = i + n) {
                lists[i] = (i + m) < k ? mergeTwoLists(lists[i], lists[i + m]) : lists[i];
            }
            m *= 2;
            n *= 2;
        }
        return lists[0];
    }

    //solution 3：分治法，采用递归的思路，不断从中间切分，不同于solution 2 
    ListNode* merge(vector <ListNode*>& lists, int l, int r) {          //l，r分别代表起止索引
        if (l == r) return lists[l];                                    //vector中只包含1个链表
        if (l > r) return nullptr;                                      //vector为空
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    //solution 4：优先队列排序合并
    struct Status {
        int val;
        ListNode* ptr;                                              //成员数据包括节点的val和所代表的节点
        bool operator < (const Status& rhs) const {                 //重载优先级队列中存放数据结构的比较运算符
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists4(vector<ListNode*>& lists) {
        for (auto node : lists) {
            if (node) q.push({ node->val, node });                  //将每个链表还未参与合并的节点中最前面的一个加入优先级队列
        }
        ListNode head, * tail = &head;                              //构建新的合并链表
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({ f.ptr->next->val, f.ptr->next });     //一个节点参与排序后，其后的节点接替其位置，加入优先级队列
        }
        return head.next;
    }
};

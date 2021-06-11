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

    //solution 1��˳��ϲ�������һ��������ѭ����vector�е�����������2�ϲ�
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        for (auto i : lists) {
            head = mergeTwoLists(head, i);
        }
        return head;
    }

    //solution 2�����η������ϵ������ϲ�����0��1��2��3��...����0��2��4��6��...
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

    //solution 3�����η������õݹ��˼·�����ϴ��м��з֣���ͬ��solution 2 
    ListNode* merge(vector <ListNode*>& lists, int l, int r) {          //l��r�ֱ������ֹ����
        if (l == r) return lists[l];                                    //vector��ֻ����1������
        if (l > r) return nullptr;                                      //vectorΪ��
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    //solution 4�����ȶ�������ϲ�
    struct Status {
        int val;
        ListNode* ptr;                                              //��Ա���ݰ����ڵ��val��������Ľڵ�
        bool operator < (const Status& rhs) const {                 //�������ȼ������д�����ݽṹ�ıȽ������
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists4(vector<ListNode*>& lists) {
        for (auto node : lists) {
            if (node) q.push({ node->val, node });                  //��ÿ������δ����ϲ��Ľڵ�����ǰ���һ���������ȼ�����
        }
        ListNode head, * tail = &head;                              //�����µĺϲ�����
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({ f.ptr->next->val, f.ptr->next });     //һ���ڵ������������Ľڵ������λ�ã��������ȼ�����
        }
        return head.next;
    }
};

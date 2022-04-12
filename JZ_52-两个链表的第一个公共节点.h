//�������������ҳ����ǵĵ�һ�������ڵ㡣
#include"ListNode.h"
#include<unordered_set>
using namespace std;

//���ù�ϣ��
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> table;
        while (headA) {
            table.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (table.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

//˫ָ�룬������Ŀ����������Ĺ�ϵ��ʱ�临�Ӷ�O(n+m)���ռ临�Ӷ�O(1)
//A:a + c = m  ;  B: b + c = n
//���1���ཻ����m == n�����ͬʱ�����һ������
//���2���ཻ�� m /= n��������a + c + b�κ󣬻�ͬʱ�����һ������
//���3�����ཻ��m == n�����ͬʱ����null
//���4�����ཻ��m /= n��������m + n �κ��ͬʱ����null
class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};

//����3����һ�α�����ȷ���ϳ��������ĳߴ磬�ڶ��α���ǰ�������߳�����Ǽ���
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        ListNode* pa = headA, * pb = headB;
        int m = 0, n = 0;
        while (pa || pb) {
            if (pa) {
                m++;
                pa = pa->next;
            }
            if (pb) {
                n++;
                pb = pb->next;
            }
        }
        if (m < n) {        //Ĭ��A�ǽϳ�������
            swap(headA, headB);
            swap(m, n);
        }
        pa = headA, pb = headB;
        int count = m - n;
        while (count-- > 0) {
            pa = pa->next;
        }
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};
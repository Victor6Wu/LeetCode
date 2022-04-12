//输入两个链表，找出它们的第一个公共节点。
#include"ListNode.h"
#include<unordered_set>
using namespace std;

//借用哈希表
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

//双指针，利用题目给出的链表的关系，时间复杂度O(n+m)，空间复杂度O(1)
//A:a + c = m  ;  B: b + c = n
//情况1：相交，且m == n，则会同时到达第一个交点
//情况2：相交， m /= n，则经历了a + c + b次后，会同时到达第一个交点
//情况3：不相交，m == n，则会同时到达null
//情况4：不相交，m /= n，经历了m + n 次后会同时到达null
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

//方法3，第一次遍历，确定较长的链表长的尺寸，第二次遍历前让其先走出多的那几步
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
        if (m < n) {        //默认A是较长的链表
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
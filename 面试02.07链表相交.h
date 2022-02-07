//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣�����������û�н��㣬���� null ��
//ע�⣬�����ָཻ���ǡ��ڵ���ͬ�������ǽڵ��ֵ���
#include"ListNode.h"
#include<unordered_set>
using namespace std;

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while (curr1 != nullptr) {
            lenA++;
            curr1 = curr1->next;
        }
        while (curr2 != nullptr) {
            lenB++;
            curr2 = curr2->next;
        }

        curr1 = headA;
        curr2 = headB;
        //ʼ����A��ʾ�����������������ظ����룬����Ҫע�⣬��ĿҪ���ܸı���������Ľṹ
        //curr1�ڳ������ϱ�����curr2�ڶ������ϱ���
        if (lenB > lenA) {
            swap(curr1, curr2);
            swap(lenA, lenB);
        }
        //��������β��
        int gap = lenA - lenB;
        while (gap > 0) {
            curr1 = curr1->next;
            gap--;
        }
        while (curr1 != nullptr) {
            if (curr1 == curr2) {          //�ڵ���ͬ������ֵ���
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return nullptr;
    }
};
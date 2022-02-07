//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
#include<unordered_set>
#include"ListNode.h"
using namespace std;

//����1������set�洢�����Ľڵ�
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

//����2������ָ��+��ѧ������������������һ����Ҫ�Ľ��ۣ�
//��ͷ������һ��ָ�룬�������ڵ�Ҳ����һ��ָ�룬������ָ��ÿ��ֻ��һ���ڵ㣬��ô��������ָ��������ʱ����ǻ�����ڵĽڵ㡣
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // ����ָ����������ʱ��head �� �����㣬ͬʱ����ֱ������
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // ���ػ������
            }
        }
        return NULL;
    }
};
//����һ�������ͷ�ڵ� head ������������� 0 �ָ�����һ��������������� ���� �� ĩβ �Ľڵ㶼���� Node.val == 0 ��
//����ÿ�������ڵ� 0 �����㽫����֮������нڵ�ϲ���һ���ڵ㣬��ֵ�������Ѻϲ��ڵ��ֵ֮�͡�Ȼ������ 0 �Ƴ����޸ĺ������Ӧ�ú����κ� 0 ��
//�����޸ĺ������ͷ�ڵ� head ��
#include"ListNode.h"
using namespace std;

//�ڵ�ֵΪ0�Ľڵ���Ϊ�������Ľڵ㣬�����Ľڵ㣬һֱ����һ����ڵ�Ϊֹ�Ľڵ�ֵ�����0��Ȼ�������ӣ�������ƶ�һλ
//��Ҫ��ע�����ѭ����ô��ֹ����ô�����һ���ڵ���0�ڵ�����
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

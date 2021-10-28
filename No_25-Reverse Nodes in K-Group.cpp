//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
#include"ListNode.h"
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
//solution 1:�Ա���룬��������洢��ת��Ľڵ㣬������ӣ�ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(N)
class Solution1 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr) return head;
		int n = 1;
		ListNode* next = head;
		while (next->next != nullptr) {
			next = next->next;
			n++;
		}
		vector<ListNode*> Q(n + 1);		//�������ݴ淭ת��Ľڵ�
		int length = n;		//��¼����ĳ���
		int GroupCount = 0;			//��¼����������ȷ�������д�ŵ���ʼ��
		while (head != nullptr) {
			n = n - k;			//��תһ��
			if (n >= 0) {
				GroupCount++;
				for (int i = k * GroupCount; i > k * (GroupCount - 1); i--) {
					Q[i] = head;
					head = head->next;
				}
			}
			else {
				for (int i = k * GroupCount + 1; i <= length; i++) {
					Q[i] = head;
					head = head->next;
				}
			}
		}
		//�ع�����
		head = Q[1];
		Q[length]->next = nullptr;
		for (int i = 2; i <= length; i++) {
			Q[i-1]->next = Q[i];
		}
		return head;
	}
};
//solution 2:ԭ�ط�ת�����ο�����
class Solution2 {
public:
    // ��תһ�����������ҷ����µ�ͷ��β
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {              
            ListNode* nex = p->next;        //�Ƚ�p��nextȡ������Ϊ��һ������Ľڵ㣬����ִ������һ��ָ����Ҳ���nex��
            p->next = prev;
            prev = p;
            p = nex;
        }
        return { tail, head };      //���ط�ת��Ľ��
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // �鿴ʣ�ಿ�ֳ����Ƿ���ڵ��� k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            // ������ C++17 ��д����Ҳ����д��
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // �����������½ӻ�ԭ����
            pre->next = head;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

//solution 3:ԭ�ط�ת��,��д����
class Solution3 {
public:
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;    // �����νӵ�ǰһ���ڵ�
        ListNode* p = head;             // �������������ָ��ڵ�
        while (prev != tail) {          // һֱ���µ�tailҲ���ν�
            ListNode* nex = p->next;    // һ��Ҫ��ȡ��p����һ���ڵ㣬��������һ��ִ�к���Ҳ�����������һ���ڵ���
            p->next = prev;
            prev = p;
            p = nex;                    // ������һ���ڵ�
        }
        return make_pair(tail,head );
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);  //����һ�����Խڵ�
        dummy->next = head;
        ListNode* pre = dummy;          //����һ��ǰ���ڵ㣬���ںͷ�ת���һ�ν����ν�

        while (head != nullptr) {
            ListNode* tail = head;
            int count = k;
            while (tail->next != nullptr && count > 1) {                    // �˴�һ����tail->next != nullptr ����������ĩβ����k-1����ᱨ��tail���Ϊnullptr
                tail = tail->next;
                count--;
            }

            //�պ�head-tail����һ������k���ڵ������
            if (count == 1) {
                pair<ListNode*,ListNode*> result = myReverse(head, tail);
                head = result.first;
                tail = result.second;
                pre->next = head;       //���µ�head��ǰ���ڵ��ν�
                head = tail->next;      //����headΪtail����һ���ڵ�
                pre = tail;             //����preΪtail�ڵ㣬��Ϊ�µ�ǰ���ڵ�
            }
            else {
                break;      //��������k���ڵ㣬�����Ѿ���������ĩ�ˣ��˳�whileѭ������
            }
        }
        return dummy->next;
    }
};
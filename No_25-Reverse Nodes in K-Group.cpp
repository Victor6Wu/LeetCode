//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
#include"ListNode.h"
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
//solution 1:自编代码，利用数组存储翻转后的节点，最后链接，时间复杂度O(N),空间复杂度O(N)
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
		vector<ListNode*> Q(n + 1);		//用数组暂存翻转后的节点
		int length = n;		//记录链表的长度
		int GroupCount = 0;			//记录组数，方便确定数组中存放的起始点
		while (head != nullptr) {
			n = n - k;			//翻转一组
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
		//重构链表
		head = Q[1];
		Q[length]->next = nullptr;
		for (int i = 2; i <= length; i++) {
			Q[i-1]->next = Q[i];
		}
		return head;
	}
};
//solution 2:原地翻转法，参考代码
class Solution2 {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {              
            ListNode* nex = p->next;        //先将p的next取出，作为下一个处理的节点，否则执行完下一行指令就找不到nex了
            p->next = prev;
            prev = p;
            p = nex;
        }
        return { tail, head };      //返回翻转后的结果
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

//solution 3:原地翻转法,自写代码
class Solution3 {
public:
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;    // 用于衔接的前一个节点
        ListNode* p = head;             // 用于逐个操作的指针节点
        while (prev != tail) {          // 一直更新到tail也被衔接
            ListNode* nex = p->next;    // 一定要先取出p的下一个节点，否则下面一行执行后就找不到真正的下一个节点了
            p->next = prev;
            prev = p;
            p = nex;                    // 处理下一个节点
        }
        return make_pair(tail,head );
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);  //构建一个惰性节点
        dummy->next = head;
        ListNode* pre = dummy;          //构建一个前驱节点，用于和翻转后的一段进行衔接

        while (head != nullptr) {
            ListNode* tail = head;
            int count = k;
            while (tail->next != nullptr && count > 1) {                    // 此处一定是tail->next != nullptr ，否则遇到末尾正好k-1个点会报错，tail会成为nullptr
                tail = tail->next;
                count--;
            }

            //刚好head-tail构成一个包含k个节点的子链
            if (count == 1) {
                pair<ListNode*,ListNode*> result = myReverse(head, tail);
                head = result.first;
                tail = result.second;
                pre->next = head;       //将新的head与前驱节点衔接
                head = tail->next;      //更新head为tail的下一个节点
                pre = tail;             //更新pre为tail节点，作为新的前驱节点
            }
            else {
                break;      //遇到不够k个节点，表明已经处理到链表末端，退出while循环即可
            }
        }
        return dummy->next;
    }
};
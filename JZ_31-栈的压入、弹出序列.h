//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У�
//�� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�
#include<vector>
#include<stack>
using namespace std;

//����Ĺؼ����ڷ�����pop����ᷢ����ʲôλ�ã���������push�Ľ�����밴�յ���pop���Ⱥ�˳�򲻿ɵߵ�
//ģ�ⷨ��ģ�����е�push���������ĳЩpush����ܻ�������ɸ�pop
//��������е�push�󣬰�˳��pop��ջ�е�ֵ��������Ӧ�÷���popped������ʣ��Ĳ���
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
            i++;
        }

        //����popջ��ʣ��Ԫ�أ������popped����ʣ�ಿ�ֲ���һһ��Ӧ����˵��false
        while (!stk.empty()) {
            if (stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
            else return false;
        }
        return true;
    }
};
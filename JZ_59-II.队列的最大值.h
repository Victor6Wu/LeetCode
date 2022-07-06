//�붨��һ�����в�ʵ�ֺ��� max_value �õ�����������ֵ��Ҫ����max_value��push_back �� pop_front �ľ�̯ʱ�临�Ӷȶ���O(1)��
//������Ϊ�գ�pop_front �� max_value ��Ҫ���� -1
#include<queue>
using namespace std;

//����1�����59-I��˼·��ά��һ�������ݼ�˫�˶��У���ʵ�ֿ��ٻ��max_value
class MaxQueue1 {
private:
    //����ţ���ֵ����ʵ��ά�����Ҳ���ԣ�pop��ʱ��ֻ��Ҫ�ж�q2����Ԫ���ǲ���q1����Ԫ�ؼ���
    queue<pair<int, int>> q1;   //���˶��У�ʵ��ʵ�ʵ�һ����һ�˳�
    deque<pair<int, int>> q2;   //ά��q1��ͬʱ��ά�������ݼ���˫�˶���q2
    int index;                  //���ڼ�¼value�Ĳ���˳��
public:
    MaxQueue1() : index(0) {

    }

    //ʱ�临�Ӷ�O(1)
    int max_value() {
        if (q2.empty()) return -1;
        return q2.front().second;
    }

    //���ʱ�临�Ӷ�O(N)��ǰ���Ԫ��ȫ�����㵥���ݼ�����ʱvalue����ǰ������Ԫ�أ�
    //���ʱ�临�Ӷ�O(1)
    void push_back(int value) {
        while (!q2.empty() && q2.back().second <= value) q2.pop_back();     //ά�������ݼ���
        q2.push_back(make_pair(index, value));
        q1.push(make_pair(index, value));
        index++;        //����index��������һ��value
    }

    //ʱ�临�Ӷ�O(1)
    int pop_front() {
        if (q1.empty()) return -1;
        int ans = q1.front().second;
        int seq = q1.front().first;
        q1.pop();
        //����q2��ά������q2�ĳ���һ��С�ڵ���q1������ֻ��Ҫ�ж�q2����Ԫ���Ƿ��Ӧq1����Ԫ�أ�������򵯳����ɣ�����Ҫwhile
        //��ʵ!q2.empty()����ɾȥ����Ϊq1�ǿձ���q2������һ��Ԫ�أ�
        if (!q2.empty() && q2.front().first <= seq)  q2.pop_front();
        return ans;
    }
};

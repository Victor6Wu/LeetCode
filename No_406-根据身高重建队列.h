//�����д���˳���һȺ��վ��һ�����У����� people ��ʾ������һЩ�˵����ԣ���һ����˳�򣩡�
//ÿ�� people[i] = [hi, ki] ��ʾ�� i ���˵����Ϊ hi ��ǰ�� ���� �� ki ����ߴ��ڻ���� hi ���ˡ�
//�������¹��첢������������ people ����ʾ�Ķ��С�
//���صĶ���Ӧ�ø�ʽ��Ϊ���� queue ������ queue[j] = [hj, kj] �Ƕ����е� j ���˵����ԣ�queue[0] �����ڶ���ǰ����ˣ���
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

//����1��������ʵ��
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int index = people[i][1];
            que.insert(que.begin() + index, people[i]);
        }
        return que;
    }
};

//����2��������ʵ��
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int index = people[i][1];
            auto it = que.begin();
            while (index--) {
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
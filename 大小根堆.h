
#include<queue>
#include<vector>
using namespace std;

//1.��������ѣ�����Ĭ�Ϸ�ʽ��
priority_queue<int> que;
//�ȼ���
priority_queue<int, vector<int>, less<int> > que;

//2.С����
priority_queue<int, vector<int>, greater<int> > que;


//�����Լ����������ͣ��������ȶ���
// 3.���� < �������ʵ�ִ󶥶�
//���Ѷ�Ԫ�أ��ȸ���x��ѡ��x����Ԫ�أ�������Ԫ�ص�xֵ��ͬ���ٸ���y��ѡ��������y�ϴ��Ԫ�أ� 
bool operator < (My_Type a, My_Type b)
{
    // ����������� 
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
// �������ȶ���
priority_queue<My_Type> que;

// 4.�º�����ʵ�ִ󶥶� 
struct cmp
{
    // ����������� 
    bool operator() (My_Type a, My_Type b)
    {
        if (a.x == b.x)return a.y < b.y;
        return a.x < b.x;
    }
};
// �������ȶ���
priority_queue<My_Type, vector<My_Type>, cmp> que;
//0,1,������,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֣�ɾ�������һ�����ֿ�ʼ��������
//������ԲȦ��ʣ�µ����һ�����֡�
//0,1,������,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֣�ɾ�������һ�����ֿ�ʼ��������
//������ԲȦ��ʣ�µ����һ�����֡�
#include<vector>
using namespace std;

//��⣺https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/jian-zhi-offer-62-yuan-quan-zhong-zui-ho-dcow/
//״̬ת�Ʒ��̣�f(n, m) = (f(n - 1, m) + m % n) % n;
//����1���ݹ鷨
class Solution1 {
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};

//����2��������/��̬�滮
class Solution2 {
public:
    int lastRemaining(int n, int m) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + m) % i;        //ע��˴��Ƕ�iȡ�࣬������n
        }
        return dp[n];
    }
};
//����3���ռ�Ľ�
class Solution3{
public:
    int lastRemaining(int n, int m) {
        int pre = 0;
        for (int i = 2; i <= n; i++) {
            pre = (pre + m) % i;        //ע��˴��Ƕ�iȡ�࣬������n
        }
        return pre;
    }
};
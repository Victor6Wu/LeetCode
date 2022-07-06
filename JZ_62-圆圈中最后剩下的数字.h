//0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。
//求出这个圆圈里剩下的最后一个数字。
//0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。
//求出这个圆圈里剩下的最后一个数字。
#include<vector>
using namespace std;

//题解：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/jian-zhi-offer-62-yuan-quan-zhong-zui-ho-dcow/
//状态转移方程：f(n, m) = (f(n - 1, m) + m % n) % n;
//方法1：递归法
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

//方法2：迭代法/动态规划
class Solution2 {
public:
    int lastRemaining(int n, int m) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + m) % i;        //注意此处是对i取余，而不是n
        }
        return dp[n];
    }
};
//方法3：空间改进
class Solution3{
public:
    int lastRemaining(int n, int m) {
        int pre = 0;
        for (int i = 2; i <= n; i++) {
            pre = (pre + m) % i;        //注意此处是对i取余，而不是n
        }
        return pre;
    }
};
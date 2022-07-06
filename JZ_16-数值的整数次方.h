//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
using namespace std;

//递归+分治
class Solution1 {
public:
    //分治法
    double quickMulti(double x, long long n) {
        if (n == 0) return 1.0;
        double y = quickMulti(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;        //根据题目意思，必须要改变n的类型，否则INT_MIN取相反数后会溢出
        return N >= 0 ? quickMulti(x, N) : 1.0 / quickMulti(x, -N);     //千万别将此处的quickMulti写成myPow了，否则递归空间会溢出
    }
};

//迭代+分治，要发现n的二进制与x^n的关系，比较难发现，n展开成2的幂次相加，对于x^n就是多个项连成，而且从低位到高位是平方的关系
class Solution2 {
    double quickMul(double x, long long N) {
        double ans = 1.0;
        //贡献初始值为x，即x^(2^0)，下一个为x^(2^1)即x^2
        double x_contribute = x;
        while (N > 0) {
            if (N % 2 == 1) {       //十进制对2取余为1，表明二进制形式中最低位为1
                ans *= x_contribute;
            }

            //贡献翻倍
            x_contribute *= x_contribute;
            //N右移1位，即舍弃最低位
            N /= 2;     //N >>= 1;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

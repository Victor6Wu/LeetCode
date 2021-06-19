//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
//The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:以减法代替除法，一次一次的减，速度太慢
	int divide1(int dividend, int divisor) {
		if (dividend == 0) return 0;

		bool signal;		//除数与被除数是否同号的标志
		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) signal = true;
		else signal = false;

		if (dividend > 0) dividend = -dividend;
		if (divisor > 0) divisor = -divisor;

		int quotient = 0;		//商
		while (dividend <= divisor) {
			dividend -= divisor;
			if (quotient == INT_MAX) return quotient;
			++quotient;
		}

		//根据signal确定返回结果的正负
		return signal == true ? quotient : -quotient;
	}

	//solution 2：除数翻倍法，妙！剔除几种特殊情况后，不断比较翻倍后的除数和被除数的大小，直到刚好小于
	int divide(int dividend, int divisor) {
		//剔除几种特殊情况
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		if (divisor == -1) {
			if (dividend > INT_MIN) return -dividend;
			else return INT_MAX;
		}

		bool signal = true;			//标记是否同号
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0)) {
			signal = false;
		}
		//对除数与被除数取正，需要修改数据类型，以免溢出
		long a = dividend;
		long b = divisor;
		a = a > 0 ? a : -a;
		b = b > 0 ? b : -b;
		//计算结果
		long res = div(a, b);
		if (signal == true) return res>INT_MAX?INT_MAX:res;
		return -res;
	}

	//创建没有乘法和除法运算符的除法函数
	int div(long a, long b) {
		if (a < b) return 0;
		long count = 1;				//a>=b,结果至少为1
		long tb = b;			//用于翻倍的除数
		while ((tb + tb) <= a) {
			count = count + count;	//结果翻倍
			tb = tb + tb;	//除数翻倍
		}
		return count + div(a - tb, b);	//去除最大的翻倍除数后递归计算剩余结果
	}
};
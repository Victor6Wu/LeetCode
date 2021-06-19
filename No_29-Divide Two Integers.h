//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
//The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:�Լ������������һ��һ�εļ����ٶ�̫��
	int divide1(int dividend, int divisor) {
		if (dividend == 0) return 0;

		bool signal;		//�����뱻�����Ƿ�ͬ�ŵı�־
		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) signal = true;
		else signal = false;

		if (dividend > 0) dividend = -dividend;
		if (divisor > 0) divisor = -divisor;

		int quotient = 0;		//��
		while (dividend <= divisor) {
			dividend -= divisor;
			if (quotient == INT_MAX) return quotient;
			++quotient;
		}

		//����signalȷ�����ؽ��������
		return signal == true ? quotient : -quotient;
	}

	//solution 2����������������޳�������������󣬲��ϱȽϷ�����ĳ����ͱ������Ĵ�С��ֱ���պ�С��
	int divide(int dividend, int divisor) {
		//�޳������������
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		if (divisor == -1) {
			if (dividend > INT_MIN) return -dividend;
			else return INT_MAX;
		}

		bool signal = true;			//����Ƿ�ͬ��
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0)) {
			signal = false;
		}
		//�Գ����뱻����ȡ������Ҫ�޸��������ͣ��������
		long a = dividend;
		long b = divisor;
		a = a > 0 ? a : -a;
		b = b > 0 ? b : -b;
		//������
		long res = div(a, b);
		if (signal == true) return res>INT_MAX?INT_MAX:res;
		return -res;
	}

	//����û�г˷��ͳ���������ĳ�������
	int div(long a, long b) {
		if (a < b) return 0;
		long count = 1;				//a>=b,�������Ϊ1
		long tb = b;			//���ڷ����ĳ���
		while ((tb + tb) <= a) {
			count = count + count;	//�������
			tb = tb + tb;	//��������
		}
		return count + div(a - tb, b);	//ȥ�����ķ���������ݹ����ʣ����
	}
};
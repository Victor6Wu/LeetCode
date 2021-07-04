//Given a non-negative integer x, compute and return the square root of x.
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:���ֲ��ң��Ա����
	int mySqrt1(int x) {
		if (x == 1) return x;
		int first_num = x / 2;
		int next_num = x;
		while (pow(first_num, 2) > x) {
			next_num = first_num;
			first_num = first_num / 2;
		}
		while (first_num < next_num) {
			if ((pow(first_num, 2) <= x) && (pow(first_num + 1, 2) > x)) return first_num;
			int temp = (first_num + next_num) / 2 ;
			if (pow(temp, 2) > x) {
				next_num = temp;
			}
			else {
				first_num = temp;
			}
		}
		return first_num;
	}

	//solution 2:���ֲ��ң��߽���Զ��Ŀ���Щ��û��Ҫ��solution1����,��ʵ�����ҵ�k^2<=x�е�����K
	int mySqrt2(int x) {
		int left = 0, right = x, ans = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (pow(mid, 2) <= x) {
				ans = mid;
				left = mid + 1;			//+1��һ������Ҫ
			}
			else {
				right = mid - 1;		//-1��һ������Ҫ
			}
		}
		return ans;
	}

	//solution 3:ţ�ٵ�����
	int mySqrt3(int x) {
		if (x == 0) {
			return 0;
		}

		double C = x, x0 = x;
		while (true) {
			double xi = 0.5 * (x0 + C / x0);
			if (fabs(x0 - xi) < 1e-7) {
				break;
			}
			x0 = xi;
		}
		return int(x0);
	}
};
};
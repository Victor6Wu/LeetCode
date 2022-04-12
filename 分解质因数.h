//因数（约数）：能够整除一个数的除数，都是该数的因数
//质因数：因数本身是素数，即不能再分解
//将一个正整数分解质因数，不包括1，例如：90 = 2 * 3 * 3 * 5
#include<iostream>
using namespace std;

//注意，此处是分解成质因数，不是求所有的因数（约数）
//如果是求所有的因数，需要将while换成if，删除num /= i
void decompose() {
	int num;
	cin >> num;
	cout << num << " = ";
	//从2开始尝试，最大是num本身
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			cout << i;
			num /= i;
			if (num != 1) {
				cout << " * ";
			}
		}
	}
	cout << endl;
	return;
}
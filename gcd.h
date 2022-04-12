//求两个正整数的最大公约数
//方法1：枚举法，将两个数的约数都求出，找出其中相同且最大的约数；
//方法2：分解质因数法，将两个数都分解成质因数，全部公有质因数相乘，积为最大公约数
//方法3：辗转相除法，用较大的数除以较小的数，能整除则较小的数为最大公约数，否则得到（较小者，余数）的结构，对这两个数继续重复上述工作，
//直至可以整除，取后者即可
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

//方法1，需要求最大的相同元素
int maxCom(vector<int> a, vector<int> b) {
	unordered_set<int> s(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = b.size() - 1; i >= 0; i--) {
		if (s.find(b[i]) != s.end()) return b[i];
	}
}
//方法2，需要求出交集，并求积
int allMultiply(vector<int> a, vector<int> b) {
	unordered_map<int, int> table;
	for (int i = 0; i < a.size(); i++) {
		table[a[i]]++;
	}
	int ans = 1;
	for (int i = 0; i < b.size(); i++) {
		if (table[b[i]] > 0) {
			ans *= b[i];
			table[b[i]]--;
		}
	}
	return ans;
}

//方法3
int gcd(int m, int n) {
	if (m < n) swap(m, n);
	while (m % n != 0) {
		int tmp = m % n;
		m = n;
		n = tmp;

	}
	return n;
}
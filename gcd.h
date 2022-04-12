//�����������������Լ��
//����1��ö�ٷ�������������Լ����������ҳ�������ͬ������Լ����
//����2���ֽ����������������������ֽ����������ȫ��������������ˣ���Ϊ���Լ��
//����3��շת��������ýϴ�������Խ�С���������������С����Ϊ���Լ��������õ�����С�ߣ��������Ľṹ�����������������ظ�����������
//ֱ������������ȡ���߼���
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

//����1����Ҫ��������ͬԪ��
int maxCom(vector<int> a, vector<int> b) {
	unordered_set<int> s(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = b.size() - 1; i >= 0; i--) {
		if (s.find(b[i]) != s.end()) return b[i];
	}
}
//����2����Ҫ��������������
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

//����3
int gcd(int m, int n) {
	if (m < n) swap(m, n);
	while (m % n != 0) {
		int tmp = m % n;
		m = n;
		n = tmp;

	}
	return n;
}
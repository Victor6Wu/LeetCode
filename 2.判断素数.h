//������������������1�������У�ֻ�ܱ�1����������������
#include<vector>
using namespace std;

//1.�ж�һ�����Ƿ�Ϊ����
//����˼·����2������sqrt(n)���ж��ܷ�n��������������ܱ�n������˵��n������
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return true;
	}
	return false;
}

//2.����һ����n���ҵ�[0, n]��Χ�ڵ���������
//����ɸ����ά��һ������Ϊ(n+1)�����飬������Ӧ��ֵ�����ݱ�ʾ�Ƿ�Ϊ��������ʼֵ������Ϊtrue����2��ʼ�������ı���������ǵ������Ӷ�Ϊ O(nlog(logn)) ��
//���е�0��1����������������С������2��ʼ��2��2��3��4...��������������������Ӧλ����Ϊfalse��ֱ������Խ�磻
//�������ҵ���С���������ظ�����һ�����������������[0,n]�еķ��������ᱻ���Ϊfalse
vector<int> findAllPrime1(int n) {
	if (n <= 1) return {};
	vector<bool> isPrime(n + 1, true);	//�洢������
	vector<int> primes;					//��¼[0, n]�е�����
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {			//����ֻ�а�˳��ᱻ���ʵ������Բ��ᱻ֮ǰ�����ı�������
			primes.push_back(i);
			//��i�ı�������Ϊfalse
			for (int k = 2 * i; k <= n; k += i) {
				isPrime[k] = false;
			}
		}
	}
	return primes;
}
//����ɸ���ڵ����⣺һ���������ܻᱻɸ���
//ŷ��ɸ���ڰ���ɸ���Ļ����ϣ���ÿ������ֻ��������С������ɸѡһ�Σ��Դﵽ���ظ���Ŀ�ġ�
//����ÿ����i�����ǽ���2��3��4...�����Ϊ������������ֻ����i * prime[j]�����Ϊ������������prime[j]��ʾ��ǰ�洢��������С�ڵ���i�ģ�
//ע�⣺��i��prime[j]�ı���ʱ��Ҫ��ǰ�˳�������ᵼ���ظ����ʣ�
//�ٸ����� ��i = 8 ��j = 1��prime[j] = 2�����������ѭ����prime[j+1] = 3��8 * 3 = 12 * 2����i = 12ʱ����㡣
vector<int> findAllPrime2(int n) {
	if (n <= 1) return {};
	vector<int> primes;		//�洢����
	vector<bool> isPrime(n + 1, true);		//Ĭ�϶���������������ʹ�����Ϊfalse�������ڱ���Ƿ���ʹ�
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes.push_back(i);
		for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
			isPrime[i * primes[j]] = false;
			if (i % primes[j] == 0) break;
		}
	}
	return primes;
}
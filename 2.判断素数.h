//素数（质数）：大于1的整数中，只能被1和它本身整除的数
#include<vector>
using namespace std;

//1.判断一个数是否为素数
//常规思路：从2遍历到sqrt(n)，判断能否被n整除，如果有数能被n整除，说明n是素数
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return true;
	}
	return false;
}

//2.给定一个数n，找到[0, n]范围内的所有素数
//埃氏筛法：维护一个长度为(n+1)的数组，索引对应数值，内容表示是否为素数，初始值都设置为true；从2开始把素数的倍数都给标记掉，复杂度为 O(nlog(logn)) 。
//其中的0、1都不是素数，从最小的素数2开始，2的2、3、4...倍数都不是素数，将对应位置置为false，直至数组越界；
//再往后找到最小的素数，重复上面一步，如此往复，最终[0,n]中的非素数都会被标记为false
vector<int> findAllPrime1(int n) {
	if (n <= 1) return {};
	vector<bool> isPrime(n + 1, true);	//存储标记情况
	vector<int> primes;					//记录[0, n]中的素数
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {			//素数只有按顺序会被访问到，绝对不会被之前的数的倍数访问
			primes.push_back(i);
			//将i的倍数都置为false
			for (int k = 2 * i; k <= n; k += i) {
				isPrime[k] = false;
			}
		}
	}
	return primes;
}
//埃氏筛存在的问题：一个合数可能会被筛多次
//欧拉筛：在埃氏筛法的基础上，让每个合数只被它的最小质因子筛选一次，以达到不重复的目的。
//对于每个数i，不是将其2、3、4...倍标记为非质数，而是只访问i * prime[j]并标记为非素数，其中prime[j]表示当前存储的素数中小于等于i的；
//注意：当i是prime[j]的倍数时，要提前退出，否则会导致重复访问：
//举个例子 ：i = 8 ，j = 1，prime[j] = 2，如果不跳出循环，prime[j+1] = 3，8 * 3 = 12 * 2，在i = 12时会计算。
vector<int> findAllPrime2(int n) {
	if (n <= 1) return {};
	vector<int> primes;		//存储素数
	vector<bool> isPrime(n + 1, true);		//默认都是素数，如果访问过就置为false，暨用于标记是否访问过
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes.push_back(i);
		for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
			isPrime[i * primes[j]] = false;
			if (i % primes[j] == 0) break;
		}
	}
	return primes;
}
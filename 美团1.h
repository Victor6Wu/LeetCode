//小团的蛋糕铺长期霸占着美团APP中“蛋糕奶茶”栏目的首位，因此总会吸引各路食客前来探店。
//小团一天最多可以烤n个蛋糕，每个蛋糕有一个正整数的重量。
//早上，糕点铺已经做好了m个蛋糕。
//现在，有一个顾客要来买两个蛋糕，他希望买这一天糕点铺烤好的最重的和最轻的蛋糕，并且希望这两个蛋糕的重量恰好为a和b。
//剩余的n - m个蛋糕可以现烤，请问小团能否满足他的要求？
//1 <= m , n <= 1000; 1 <= a, b <= 1000
#include<vector>
#include<iostream>
using namespace std;

//将所有true的情况考虑到，其余都是false
void solution() {
    int m, n, a, b;
    int num;
    while (cin >> n >> m >> a >> b) {
        vector<int> vec(m, 0);
        int maxElement = 0;
        int minElement = 1001;
        if (a > b) swap(a, b);
        for (int i = 0; i < m; i++) {
            cin >> num;
            vec[i] = num;
            maxElement = max(maxElement, num);
            minElement = min(minElement, num);
        }
        bool sign = true;
        //情况1
        if (a < minElement && b > maxElement) {
            if (n - m >= 2) {
                cout << "YES";
                sign = false;
            }
        }
        //情况2
        else if (a == minElement && b == maxElement) {
            if (n >= 2) {
                cout << "YES";
                sign = false;
            }
        }
        //情况3，a或b有一个已经满足条件，这个是最容易忘记的
        else if ((a == minElement && b > maxElement) || (a < minElement && b == maxElement)) {
            if (n - m >= 1) {
                cout << "YES";
                sign = false;
            }
        }
        if (sign) cout << "NO";
        cout << endl;
    }
    return;
}
//С�ŵĵ����̳��ڰ�ռ������APP�С������̲衱��Ŀ����λ������ܻ�������·ʳ��ǰ��̽�ꡣ
//С��һ�������Կ�n�����⣬ÿ��������һ����������������
//���ϣ�������Ѿ�������m�����⡣
//���ڣ���һ���˿�Ҫ�����������⣬��ϣ������һ�����̿��õ����صĺ�����ĵ��⣬����ϣ�����������������ǡ��Ϊa��b��
//ʣ���n - m����������ֿ�������С���ܷ���������Ҫ��
//1 <= m , n <= 1000; 1 <= a, b <= 1000
#include<vector>
#include<iostream>
using namespace std;

//������true��������ǵ������඼��false
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
        //���1
        if (a < minElement && b > maxElement) {
            if (n - m >= 2) {
                cout << "YES";
                sign = false;
            }
        }
        //���2
        else if (a == minElement && b == maxElement) {
            if (n >= 2) {
                cout << "YES";
                sign = false;
            }
        }
        //���3��a��b��һ���Ѿ�������������������������ǵ�
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
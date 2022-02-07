//编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」定义为：
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果 可以变为  1，那么这个数就是快乐数。

//如果 n 是快乐数就返回 true ；不是，则返回 false 。
#include<unordered_set>
#include<algorithm>
using namespace std;

//用unordered_map在循环计算的过程中记录每次的“按位平凡和”，当某一结果重复出现时（1以外），即可确定该数为非快乐数；当计算结果为1时，即可确定是快乐数
class Solution {
public:
    int SumofSquare(int num) {
        int sum = 0;
        while (num >= 1) {
            int tmp = num % 10;
            sum += tmp * tmp;
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_set<int> table;
        table.insert(n);
        while (1) {
            int squareSum = SumofSquare(n);
            if (squareSum == 1) return true;
            if (table.find(squareSum) != table.end()) {
                return false;
            }
            table.insert(squareSum);
            n = squareSum;
        }
        return 0;
    }
};
//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
#include<string>
using namespace std;

//主体思想类似密码锁，n表示最大的数，从0000...开始，从小到大增长，某一位出现1的次数取决于该位左右的值
//对于当前位的值，要分情况考虑：0、1、2...
//时间复杂度 O(log n)，空间复杂度O(1)
class Solution {
public:
    int countDigitOne(int n) {
        long long digit = 1;    //用于表示位数
        int highNum, lowNum, curNum;
        int ans = 0;
        while (digit <= n) {
            highNum = n / (digit * 10);     //当前位左侧的高位
            lowNum = n % digit;             //当前位右侧的低位  
            curNum = (n % (digit * 10) - lowNum) / digit;   //当前位上的数
            //当前位数值为0
            if (curNum == 0) ans += (highNum * digit);
            //当前位数值为1
            else if (curNum == 1) ans += (highNum * digit + 1 + lowNum);
            //当前位数值为2-9
            else ans += ((highNum + 1) * digit);

            digit *= 10;
        }
        return ans;
    }
};

//暴力法1
class Solution1 {
public:
    int count_1(string num) {
        int count = 0;
        for (const char& c : num) {
            if (c == '1') count++;
        }
        return count;
    }

    int countDigitOne(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += count_1(to_string(i));
        }
        return ans;
    }
};

//暴力法2
class Solution2 {
public:
    int count_1(string num) {
        int count = 0;
        for (const char& c : num) {
            if (c == '1') count++;
        }
        return count;
    }

    int countDigitOne(int n) {
        int ans = 0;
        string s;
        for (int i = 1; i <= n; i++) {
            s += to_string(i);
        }
        return count_1(s);
    }
};
//����һ������ n ����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
#include<string>
using namespace std;

//����˼��������������n��ʾ����������0000...��ʼ����С����������ĳһλ����1�Ĵ���ȡ���ڸ�λ���ҵ�ֵ
//���ڵ�ǰλ��ֵ��Ҫ��������ǣ�0��1��2...
//ʱ�临�Ӷ� O(log n)���ռ临�Ӷ�O(1)
class Solution {
public:
    int countDigitOne(int n) {
        long long digit = 1;    //���ڱ�ʾλ��
        int highNum, lowNum, curNum;
        int ans = 0;
        while (digit <= n) {
            highNum = n / (digit * 10);     //��ǰλ���ĸ�λ
            lowNum = n % digit;             //��ǰλ�Ҳ�ĵ�λ  
            curNum = (n % (digit * 10) - lowNum) / digit;   //��ǰλ�ϵ���
            //��ǰλ��ֵΪ0
            if (curNum == 0) ans += (highNum * digit);
            //��ǰλ��ֵΪ1
            else if (curNum == 1) ans += (highNum * digit + 1 + lowNum);
            //��ǰλ��ֵΪ2-9
            else ans += ((highNum + 1) * digit);

            digit *= 10;
        }
        return ans;
    }
};

//������1
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

//������2
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
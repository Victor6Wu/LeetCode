//дһ������ StrToInt��ʵ�ְ��ַ���ת��������������ܡ�����ʹ�� atoi �����������ƵĿ⺯����
//��Ŀ��
#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int index = 0;
        while (index < str.size() && str[index] == ' ') index++;
        if (str.size() == 0 || index == str.size()) return 0;
        if (str[index] != '+' && str[index] != '-' && (str[index] < 48 || str[index] > 57)) return 0;
        int ans = 0;
        if (str[index] == '+' || (str[index] >= 48 && str[index] <= 57)) {
            if (str[index] == '+') index++;
            while (index < str.size() && str[index] >= 48 && str[index] <= 57) {
                int tmp = str[index] - '0';
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && tmp > 7)) return INT_MAX;
                ans = ans * 10 + tmp;
                index++;
            }
        }
        else if (str[index] == '-') {
            index++;
            while (index < str.size() && str[index] >= 48 && str[index] <= 57) {
                int tmp = str[index] - '0';
                if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && tmp > 8)) return INT_MIN;
                ans = ans * 10 - tmp;
                index++;
            }
        }
        return ans;
    }
};
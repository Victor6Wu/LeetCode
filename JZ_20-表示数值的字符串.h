//��ֵ�ɼ������֣����ɿո�+С��/����+e�������(��ѡ)+���ɿո�
//С��(��˳��)��+-�����֣���.�������֣�
//����(��˳��)��+-�����֣�
#include<string>
using namespace std;

//����1����ģ������жϣ������e�����������Ӵ��ֱ��жϣ� ʱ�临�Ӷ�3 * O(N)
class Solution1 {
public:
    bool isDecimal(string s) {
        int countSign = 0, countPoint = 0, countOther = 0, countNum = 0;
        for (const char& c : s) {
            if (c == '+' || c == '-') countSign++;
            else if (c == '.') countPoint++;
            else if (c >= 48 && c <= 57) countNum++;
            else countOther++;
        }
        if (countSign >= 2 || countPoint != 1 || countNum < 1 || countOther > 0) return false;
        if (countSign == 1 && (s[0] != '+' && s[0] != '-')) return false;
        return true;
    }

    bool isInteger(string s) {
        int countSign = 0, countPoint = 0, countOther = 0, countNum = 0;
        for (const char& c : s) {
            if (c == '+' || c == '-') countSign++;
            else if (c == '.') countPoint++;
            else if (c >= 48 && c <= 57) countNum++;
            else countOther++;
        }
        if (countNum < 1 || countSign > 1 || countPoint > 0 || countOther > 0) return false;
        if (countSign == 1 && (s[0] != '+' && s[0] != '-')) return false;
        return true;
    }

    bool isNumber(string s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;
        int countE = 0, indexE = -1, countSpace = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                indexE = i;
                countE++;
            }
            else if (s[i] == ' ') countSpace++;
        }
        if (countE > 1 || countSpace >= 1) return false;
        else if (countE == 1 && (indexE == start) || (indexE == end)) return false;
        if (countE == 1) {
            string s1(s.begin() + start, s.begin() + indexE);
            string s2(s.begin() + indexE + 1, s.begin() + end + 1);
            return (isDecimal(s1) || isInteger(s1)) && isInteger(s2);
        }
        return isDecimal(s.substr(start, (end - start + 1))) || isInteger(s.substr(start, (end - start + 1)));
    }
};

//����2��һ�α�����ͳ�ƽ��
class Solution2 {
public:
    bool isNumber(string s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;
        //��startλ����������E��end����¼E���ֵĴ�����λ�ã��ո���ֵĴ�����С������ֵĴ��������ֳ��ֵĴ����������ַ����ֵ�����
        int countSign = 0, countE = 0, indexE = -1, countSpace = 0, countPoint = 0, countNum = 0, countOther = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] == '+' || s[i] == '-') countSign++;
            else if (s[i] == 'e' || s[i] == 'E') {
                countE++;
                indexE = i;
                break;
            }
            else if (s[i] == ' ') countSpace++;
            else if (s[i] == '.') countPoint++;
            else if (s[i] >= 48 && s[i] <= 57) countNum++;
            else countOther++;
        }

        //�жϵ�һ�����Ƿ�������С������������e��
        if (countSpace != 0 || countOther != 0 || countSign > 1 || countPoint > 1 || countNum < 1) return false;
        if (countSign == 1 && s[start] != '+' && s[start] != '-') return false;
    
        //�ж�e����Ĳ����Ƿ�Ϊ����
        if (countE == 1) {
            //����ͳ��ֵ
            countSign = 0, countSpace = 0, countPoint = 0, countNum = 0, countOther = 0;
            for (int i = indexE + 1; i <= end; i++) {
                if (s[i] == '+' || s[i] == '-') countSign++;
                else if (s[i] == ' ') countSpace++;
                else if (s[i] == '.') countPoint++;
                else if (s[i] >= 48 && s[i] <= 57) countNum++;
                else countOther++;
            }
            if (countSpace != 0 || countOther != 0 || countSign > 1 || countPoint >= 1 || countNum < 1) return false;
            if (countSign == 1 && s[indexE + 1] != '+' && s[indexE + 1] != '-') return false;
        }
        return true;
    }
};
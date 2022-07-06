//数值由几个部分：若干空格+小数/整数+e后跟整数(可选)+若干空格
//小数(按顺序)：+-，数字，‘.’，数字；
//整数(按顺序)：+-，数字；
#include<string>
using namespace std;

//方法1：分模块进行判断，如果有e就左右两个子串分别判断， 时间复杂度3 * O(N)
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

//方法2：一次遍历，统计结果
class Solution2 {
public:
    bool isNumber(string s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;
        //从start位往后搜索到E或end，记录E出现的次数和位置；空格出现的次数；小数点出现的次数；数字出现的次数；其他字符出现的字数
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

        //判断第一部分是否整数或小数（无论有无e）
        if (countSpace != 0 || countOther != 0 || countSign > 1 || countPoint > 1 || countNum < 1) return false;
        if (countSign == 1 && s[start] != '+' && s[start] != '-') return false;
    
        //判断e后面的部分是否为整数
        if (countE == 1) {
            //更新统计值
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
//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
#include<string>
using namespace std;

//字符串从0开始，后续加1、2、3、4...位的数字，因此可以判断出每一阶段字符串的长度范围，根据n和字符串长度的范围先确定n所指向的数在哪个范围，有几位数
//startNum就是某种数的第一个数，如1、10、100、1000，再根据剩余的字符长度整除位数，确定具体是哪个数字，再根据余数确定是第几位
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        //startNum表示每个范围的首元素：1、100、1000...；factor1表示范围内整数的个数：9、99、999...；factor2表示范围内数字的位数：1、2、3、...
        long long startNum = 1, factor1 = 9, factor2 = 1;
        while (n - (factor1 * factor2) > 0) {       //n - (factor1 * factor2) > 0可以锁定范围
            n -= (factor1 * factor2);
            startNum *= 10;
            factor1 *= 10;
            factor2++;
        }
        int quotient = n / factor2;      //商用于表示n指向的数是该范围中的第几个数
        int remainder = n % factor2;     //余数表示n指向的数中的第几位

        //要注意的是，余数为0表示的是n指向的数的最后一位，要将商-1
        if (remainder == 0) {
            quotient--;
            remainder = factor2;
        }
        string currNum = to_string(startNum + quotient);
        return currNum[remainder - 1] - '0';
    }
};
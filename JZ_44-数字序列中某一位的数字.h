//������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵȡ�
#include<string>
using namespace std;

//�ַ�����0��ʼ��������1��2��3��4...λ�����֣���˿����жϳ�ÿһ�׶��ַ����ĳ��ȷ�Χ������n���ַ������ȵķ�Χ��ȷ��n��ָ��������ĸ���Χ���м�λ��
//startNum����ĳ�����ĵ�һ��������1��10��100��1000���ٸ���ʣ����ַ���������λ����ȷ���������ĸ����֣��ٸ�������ȷ���ǵڼ�λ
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        //startNum��ʾÿ����Χ����Ԫ�أ�1��100��1000...��factor1��ʾ��Χ�������ĸ�����9��99��999...��factor2��ʾ��Χ�����ֵ�λ����1��2��3��...
        long long startNum = 1, factor1 = 9, factor2 = 1;
        while (n - (factor1 * factor2) > 0) {       //n - (factor1 * factor2) > 0����������Χ
            n -= (factor1 * factor2);
            startNum *= 10;
            factor1 *= 10;
            factor2++;
        }
        int quotient = n / factor2;      //�����ڱ�ʾnָ������Ǹ÷�Χ�еĵڼ�����
        int remainder = n % factor2;     //������ʾnָ������еĵڼ�λ

        //Ҫע����ǣ�����Ϊ0��ʾ����nָ����������һλ��Ҫ����-1
        if (remainder == 0) {
            quotient--;
            remainder = factor2;
        }
        string currNum = to_string(startNum + quotient);
        return currNum[remainder - 1] - '0';
    }
};
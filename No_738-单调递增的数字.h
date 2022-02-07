//����һ���Ǹ����� `N`���ҳ�С�ڻ���� `N` ������������ͬʱ���������Ҫ���������λ���ϵ������ǵ���������
//�����ҽ���ÿ������λ���ϵ����� `x` �� `y` ���� `x <= y` ʱ�����ǳ���������ǵ��������ġ���
#include<vector>
using namespace std;

//����1���Ա���룬��n�Ȱ�λ����洢��������
class Solution1 {
private:
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        vector<int> vec(10, 0);         //������Ŀ����n�ķ�Χ��������10λ�������洢
        int count = 0;                  //��¼λ����������������������ֹλ��
        while (n > 0) {
            vec[count] = n % 10;
            count++;                    //��Ϊ�Ǵӵ�λ����λ����������С�˷���¼�ģ�countҪ��ʵ������λ�ô�1
            n = n / 10;
        }
        bool sign = true;       //��ǰ�����Ƿ����㵹�𵥵��������ص㣨ѭ�����ж�������
        int errIndex = 0;       //��¼�����ǰһλ�����Ǵ���λ����
        while (sign) {
            for (int i = count - 1; i >= 1; i--) {      //��Ϊ��С�˼��������Ե������
                if (vec[i] > vec[i - 1]) {      //�����쳣ʱ
                    errIndex = i;               //��¼�쳣λ�õ�ǰһλ
                    sign = true;
                    break;
                }
                sign = false;                   //û���쳣��ѭ����־��Ϊfalse
            }
            if (sign == true) {                 //�������쳣ʱ
                vec[errIndex]--;                //���쳣��ǰһλ-1��ʣ��ĵ�λ��Ϊ9
                for (int j = errIndex - 1; j >= 0; j--) {
                    vec[j] = 9;
                }
            }
        }
        //������֯���
        int res = 0;
        for (int i = count - 1; i >= 0; i--) {
            res *= 10;
            res += vec[i];
        }
        return res;
    }
};

//����2����nת���ַ�������
class Solution2 {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag������Ǹ�ֵ9�����￪ʼ
        // ����Ϊ���Ĭ��ֵ��Ϊ�˷�ֹ�ڶ���forѭ����flagû�б���ֵ�������ִ��
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        //��ȷ�������һ��-1��λ�ú�ͳһ�Ժ����λ�ĳ�9�������˷���1������whileѭ��
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
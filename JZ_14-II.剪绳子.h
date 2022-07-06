//���˴���Խ������µ���������
using namespace std;
#define p 1000000007


//���ǰ���ԭ�ȵ�˼·������Ҫ��дpow���������JZ_16
class Solution {
private:
    //���ַ����ָ࣬��count�ڲ��ϵĶ��ۣ������ڲ��ϵ�ƽ��������JZ_16�������Ľ��ͱȽϺ����
    long long pow(long long num, int count, int div) {  //num�м����ִ���INT_MAX�����������Ҫת��long long����
        long long ans = 1;      //�˴�ans���붨��Ϊlong long���ͣ���Ϊ�������ִ���INT_MAX�����
        while (count > 0) {
            //ָ��count����2֮ǰ�����ж����Ƿ����1
            if (count % 2) ans = ans * num % div;  //���ض��ᾭ�� 1 / 2 = 0...1
            num = (num % div) * (num % div);        //����num=3�����Բ���Ҫ%��������Ҫ�Ƿ�ֹ��һ�μ����ʱ��num���Ѿ�����INT_MAX��
            num %= div;     //num�ڷ����Ĺ����У�ÿ�ζ���divȡ�࣬�����˴�С
            count /= 2;
        }
        return ans;
    }

public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int count = n / 3;
        int remain = n % 3;
        long long ans;        //�����ans���붨��Ϊlong long���ͣ���Ϊ����ans��*4��*2
        if (remain == 0) ans = pow(3, count, p);
        else if (remain == 1) {
            ans = pow(3, count - 1, p);
            ans = ans * 4 % p;                  //�˴�ȡ�಻Ҫ����
        }
        else {
            ans = pow(3, count, p) * 2 % p;     //�˴�ȡ�಻Ҫ����
        }
        return ans;
    }
};
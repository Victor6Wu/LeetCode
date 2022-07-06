//ʵ�� pow(x, n) �������� x �� n ���ݺ���������xn��������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
using namespace std;

//�ݹ�+����
class Solution1 {
public:
    //���η�
    double quickMulti(double x, long long n) {
        if (n == 0) return 1.0;
        double y = quickMulti(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;        //������Ŀ��˼������Ҫ�ı�n�����ͣ�����INT_MINȡ�෴��������
        return N >= 0 ? quickMulti(x, N) : 1.0 / quickMulti(x, -N);     //ǧ��𽫴˴���quickMultiд��myPow�ˣ�����ݹ�ռ�����
    }
};

//����+���Σ�Ҫ����n�Ķ�������x^n�Ĺ�ϵ���Ƚ��ѷ��֣�nչ����2���ݴ���ӣ�����x^n���Ƕ�������ɣ����Ҵӵ�λ����λ��ƽ���Ĺ�ϵ
class Solution2 {
    double quickMul(double x, long long N) {
        double ans = 1.0;
        //���׳�ʼֵΪx����x^(2^0)����һ��Ϊx^(2^1)��x^2
        double x_contribute = x;
        while (N > 0) {
            if (N % 2 == 1) {       //ʮ���ƶ�2ȡ��Ϊ1��������������ʽ�����λΪ1
                ans *= x_contribute;
            }

            //���׷���
            x_contribute *= x_contribute;
            //N����1λ�����������λ
            N /= 2;     //N >>= 1;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

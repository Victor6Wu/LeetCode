//多了大数越界情况下的求余问题
using namespace std;
#define p 1000000007


//还是按照原先的思路，不过要改写pow函数，借鉴JZ_16
class Solution {
private:
    //二分法求余，指数count在不断的对折，底数在不断的平方，按照JZ_16迭代法的解释比较好理解
    long long pow(long long num, int count, int div) {  //num中间会出现大于INT_MAX的情况，所有要转成long long类型
        long long ans = 1;      //此处ans必须定义为long long类型，因为下面会出现大于INT_MAX的情况
        while (count > 0) {
            //指数count整除2之前，先判断其是否会余1
            if (count % 2) ans = ans * num % div;  //最后必定会经历 1 / 2 = 0...1
            num = (num % div) * (num % div);        //本题num=3，可以不需要%，这里主要是防止第一次计算的时候num就已经大于INT_MAX了
            num %= div;     //num在翻倍的过程中，每次都对div取余，控制了大小
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
        long long ans;        //这里的ans必须定义为long long类型，因为后面ans会*4或*2
        if (remain == 0) ans = pow(3, count, p);
        else if (remain == 1) {
            ans = pow(3, count - 1, p);
            ans = ans * 4 % p;                  //此处取余不要忘了
        }
        else {
            ans = pow(3, count, p) * 2 % p;     //此处取余不要忘了
        }
        return ans;
    }
};
//给定一个非负整数 `N`，找出小于或等于 `N` 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//（当且仅当每个相邻位数上的数字 `x` 和 `y` 满足 `x <= y` 时，我们称这个整数是单调递增的。）
#include<vector>
using namespace std;

//方法1：自编代码，将n先按位逆序存储在数组中
class Solution1 {
private:
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        vector<int> vec(10, 0);         //根据题目给的n的范围，必须用10位数组来存储
        int count = 0;                  //记录位数，即填入数组后，数组的终止位置
        while (n > 0) {
            vec[count] = n % 10;
            count++;                    //因为是从低位往高位处理，数组是小端法记录的；count要比实际索引位置大1
            n = n / 10;
        }
        bool sign = true;       //当前数组是否满足倒叙单调自增的特点（循环的判断条件）
        int errIndex = 0;       //记录错误的前一位而不是错误位本身
        while (sign) {
            for (int i = count - 1; i >= 1; i--) {      //因为是小端计数，所以倒叙遍历
                if (vec[i] > vec[i - 1]) {      //出现异常时
                    errIndex = i;               //记录异常位置的前一位
                    sign = true;
                    break;
                }
                sign = false;                   //没有异常，循环标志置为false
            }
            if (sign == true) {                 //当出现异常时
                vec[errIndex]--;                //将异常的前一位-1，剩余的低位置为9
                for (int j = errIndex - 1; j >= 0; j--) {
                    vec[j] = 9;
                }
            }
        }
        //重新组织结果
        int res = 0;
        for (int i = count - 1; i >= 0; i--) {
            res *= 10;
            res += vec[i];
        }
        return res;
    }
};

//方法2，将n转成字符串即可
class Solution2 {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        //在确定好最后一个-1的位置后，统一对后面的位改成9，避免了方法1中外层的while循环
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
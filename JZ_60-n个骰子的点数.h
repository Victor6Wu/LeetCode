#include<vector>
using namespace std;

//动态规划法
//仔细观察n与n-1结果的相关性可以发现：
//1.数组长度为5 * n - 1
//2.抛开索引不谈，数值上来说dp1[i] = sum(dp0[i - j]) * 1 / 6.0，其中j为1~6
//3.数组首元素巧好为n，dp0与dp1在首元素上刚好相差1
//4.难点在于设置好边界条件，要保证找对那些构成dp1[i]的元素，既不能多也不能少
class Solution1 {
public:
    vector<double> dicesProbability(int N) {
        vector<double> dp0(5 * N + 1, 1.0 / 6); //最终数组的长度会达到5 * N + 1，可以直接设置为这么长，后面只要注意控制索引范围即可
        if (N == 1) return dp0;
        vector<double> dp1(5 * N + 1, 1.0 / 6);
        double k = 1.0 / 6;
        for (int n = 2; n <= N; n++) {      //当前骰子个数
            for (int i = 0; i < 5 * n + 1; i++) {       //按顺序填充当前骰子个数对应的数组，要控制索引范围
                double tmp = 0;
                //累计当前骰子数值为1~6时dp0对应的结果
                for (int j = 1; j <= 6; j++) {

                    //！！！这里非常重要，dp0表示的是n-1个骰子的结果，要控制索引在其范围内！！！
                    if (i - j + 1 >= 0 && i - j + 1 < 5 * (n - 1) + 1)  //n个骰子的首元素值比n-1个骰子的首元素大1，因此这里有个+1
                        tmp += dp0[i - j + 1];
                }

                dp1[i] = k * tmp;
            }

            //for (int k = 0; k < 5 * n + 1; k++) dp0[k] = dp1[k];
            dp0.assign(dp1.begin(), dp1.end());
            
        }
        return dp0;
    }
};

//写法2，自底向上理解，这样不需要像写法1那样，考虑越界问题
class Solution2 {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6.0);
        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); j++) {       //遍历上一个数组的每个数
                for (int k = 0; k < 6; k++) {           //其基础上可以加上1、2、3、4、5、6
                    tmp[j + k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};
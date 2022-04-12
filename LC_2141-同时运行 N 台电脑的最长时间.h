//笔试题目：给一个长度为5的数组，全都是非负数，每次取其中4个数一起减1，请问最多可以进行多少次减1？
//力扣题目：你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries，
//其中第 i 个电池可以让一台电脑运行 batteries[i] 分钟。你想使用这些电池让全部n台电脑同时运行。
//电池可以在电脑中无缝切换。
//请你返回你可以让 n 台电脑同时运行的 最长分钟数。
#include<vector>
#include<numeric>
using namespace std;

//力扣题目中，n=4，batteries.size=5，即为笔试题目
//本题思路：1.要转变思考的方向，有点像木桶效应，如果所有电池的电量相等（即电量均衡），那么最长运行的时间就会久；
//		   2.那么就从最长的时间出发，采用二分法逐渐找到实际的最长时间；
//		   3.最难点在于理清楚判断条件是什么：对于当前给定的运行时间k，这些电池能不能满足条件；
//		   4.满足条件，是指哪些条件：对于一个电池x，其运行次数occ(x) = min(batteries[x],k)，如果所有occ(x)的和大于等于 k * n，说明可以给每个电脑分配电池
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n, ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long total = 0;        //累计occ(x)
            for (int cap : batteries) {
                total += min(static_cast<long long>(cap), mid);
            }
            if (total >= n * mid) {     //当前mid可行
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
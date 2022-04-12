//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
#include<vector>
using namespace std;

//注意审题，输出的是和为target的“连续”正整数序列；至少包含2个数
//暴力法，从 1 → target/2 依次作为起始值，进行累加操作，如果和等于target就保存，大于则跳到下一个起始值
//时间复杂度O(target·sqrt(target))
class Solution1 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int i = 1; i <= limit; ++i) {
            for (int j = i; j < target; ++j) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                }
                else if (sum == target) {
                    res.clear();
                    //将i开始到j的数字存储
                    for (int k = i; k <= j; ++k) {
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};

//暴力法优化，之前从i起，到j止是通过遍历的方式计算的，而实际累计和是有公式可循的，根据一元二次方程有无解进一步得出j即可
//时间复杂度O(target)
class Solution2 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int x = 1; x <= limit; ++x) {
            long long delta = 1 - 4 * (x - 1ll * x * x - 2 * target);
            if (delta < 0) {
                continue;
            }
            int delta_sqrt = (int)sqrt(delta + 0.5);
            if (1ll * delta_sqrt * delta_sqrt == delta && (delta_sqrt - 1) % 2 == 0) {
                int y = (-1 + delta_sqrt) / 2; // 另一个解(-1-delta_sqrt)/2必然小于0，不用考虑
                if (x < y) {
                    res.clear();
                    for (int i = x; i <= y; ++i) {
                        res.emplace_back(i);
                    }
                    vec.emplace_back(res);
                }
            }
        }
        return vec;
    }
};

//双指针法，其实思路也是来自于方法1，优化了已经枚举的部分，避免了重复遍历
//注意循环的终止条件
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target <= 2) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        int left = 1, right = 2;
        while (left < right) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                tmp.clear();
                for (int i = left; i <= right; i++) {
                    tmp.push_back(i);
                }
                ans.push_back(tmp);
                left++;         //此处left++一定不能忘记，否则会陷入循环
            }
            else if (sum < target) right++;
            else left++;
        }
        return ans;
    }
};
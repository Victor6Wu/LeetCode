//给你一个下标从 0 开始、长度为 n 的整数数组 nums 和一个整数 k ，返回满足下述条件的下标对 (i, j) 的数目：
//0 <= i < j <= n - 1 且
//nums[i] * nums[j] 能被 k 整除。
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;

//本题主要问题是，容易超时，容易溢出int
class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                cnt[i] = 0;
                if (i * i != k) {
                    cnt[k / i] = 0;
                }
            }
        }

        long long ans = 0;
        for (int num : nums) {
            int need = k / gcd(num, k);
            ans += cnt[need];
            for (auto&& [fac, occ] : cnt) {
                if (num % fac == 0) {
                    ++occ;
                }
            }
        }

        return ans;
    }
};

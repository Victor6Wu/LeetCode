//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//排序
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//借用哈希表
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        int n = nums.size();
        for (const int& it : nums) {
            table[it]++;
            if (table[it] > n / 2) return it;
        }
        return 0;
    }
};

//投票算法，候选值，及其积分；遍历到每个元素先判断其为0还是大于0，是0则其作为候选，大于0则判断是否与之前的候选相等，调整count
//写法1
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (const int& num : nums) {
            if (count == 0) {
                candidate = num;
                count++;
            }
            else {
                if (num == candidate) count++;
                else count--;
            }
        }
        return candidate;
    }
};
//写法2
class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
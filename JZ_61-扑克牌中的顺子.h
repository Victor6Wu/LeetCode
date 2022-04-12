//本题准确来说和扑克牌没什么关系，给定长度为5的数组，包含[0,13]的数字，其中0可以表示任意的数字，判断数组中的数能不能排成顺子
//如[0，0，1，2，5]可以看作[1，2，3，4，5]
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//方法1
class Solution1 {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, index = 0;
        while (nums[index] == 0) {
            count++;
            index++;
        }
        for (int i = index + 1; i <= 4; i++) {
            if (nums[i] - nums[i - 1] == 1) continue;
            else if (nums[i] - nums[i - 1] == 0) return false;
            else {
                if (nums[i] - nums[i - 1] - 1 <= count) {
                    count -= (nums[i] - nums[i - 1] - 1);
                }
                else return false;
            }
        }
        return true;
    }
};

//方法2，提取关键条件：
//1.除了0以外没有重复元素，2.除了0以外，max - min < 5
//关于重复与否，可以用map确定，也可以排序后确定，因此有两种方法：map+遍历；或者排序+遍历
class Solution2 {
public:
    bool isStraight(vector<int>& nums) {
        unordered_map<int, int> table;
        int minNum = 14, maxNum = -1;
        for (int i = 0; i < 5; i++) {
            if (nums[i] != 0) {
                if (table[nums[i]] != 0) return false;
                table[nums[i]]++;
                minNum = min(minNum, nums[i]);
                maxNum = max(maxNum, nums[i]);
            }
        }
        if (maxNum - minNum < 5) return true;
        return false;
    }
};

class Solution3 {
public:
    bool isStraight(vector<int>& nums) {
        int minIndex = 0;       //记录第一个不是0的位置
        sort(nums.begin(), nums.end());
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0) minIndex++;
            else if (nums[i] == nums[i + 1]) return false;
        }
        if (nums[4] - nums[minIndex] < 5) return true;
        return false;
    }
};
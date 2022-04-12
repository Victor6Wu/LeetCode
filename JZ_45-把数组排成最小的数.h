//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//本题的关键在于想一个合适的排序算法，对于两个数x,y，怎么判断x在前还是y在前呢？
//第一直观的想法是利用基排序，但有些情况考虑起来很麻烦，比如3,30中30应该小于3
//所以本题的排序思想：拼接字符串x+y>y+x，则x“大于”y

//写法1，在快排的基础上修改
class Solution1 {
public:
    void quicksort(vector<string>& nums, int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        string pivot = nums[left];
        while (i < j) {
            while (i < j && pivot + nums[j] <= nums[j] + pivot) j--;
            if (i < j) nums[i] = nums[j];    //小的挪到前面去
            while (i < j && nums[i] + pivot <= pivot + nums[i]) i++;
            if (i < j) nums[j] = nums[i];     //大的挪到后面去
        }
        nums[i] = pivot;
        quicksort(nums, left, i - 1);
        quicksort(nums, i + 1, right);
    }
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        for (const int& num : nums) {
            vec.push_back(to_string(num));
        }
        quicksort(vec, 0, vec.size() - 1);
        string ans;
        for (const string str : vec) {
            ans += str;
        }
        return ans;
    }
};

//修改内置函数
class Solution2 {
public:
    static bool cmp(string& a, string& b) {
        return a + b < b + a;
    }
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        for (const int& num : nums) {
            vec.push_back(to_string(num));
        }
        sort(vec.begin(), vec.end(), cmp);
        string ans;
        for (const string& str : vec) {
            ans += str;
        }
        return ans;
    }
};
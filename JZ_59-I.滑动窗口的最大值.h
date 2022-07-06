//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值.
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//方法1：暴力法
//改进1：可以利用双端队列优化：增添一个元素的时候通过比较就可以更新最大值；删除元素的时候，若恰好是最大值，就得遍历窗口得到新的最大值，代码略
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        int index = 0;
        vector<int> ans;
        while (index + k <= nums.size()) {
            auto it = max_element(nums.begin() + index, nums.begin() + index + k);
            ans.push_back(*it);
            index++;
        }
        return ans;
    }
};

//方法2：优先队列
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = { q.top().first };
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            //只要pop出不在窗口中的元素即可
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

//方法3：双端队列实现的“单调队列”，按顺序单调递减；时间复杂度O(N)
//将窗内的元素维护成一个单调递减队列，那么最大值一定在队首；
//窗口移动，新的元素与队尾进行比较，如果比队尾小就直接放在队尾，如果比队尾大就要弹出队尾，继续比较，直至满足单调递减的特点，或者队列为空
//队列中保存的是索引，而非元素本身，这样方便判断是否在窗内
class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        deque<int> Q;       //里面存储的是nums中的索引而非元素本身
        for (int i = 0; i < k; i++) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i);
        }
        vector<int> ans = { nums[Q.front()] };
        for (int i = k; i < nums.size(); i++) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i);

            //要将不在窗内的元素pop出去
            while (Q.front() <= i - k) Q.pop_front();
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};
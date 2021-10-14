//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
//You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution{
public:
	//solution 1:逐个窗口内比较，时间复杂度O(N^2)
	vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		vector<int> ans;
		for (int i = 0; i <= nums.size() - k; i++) {
			int Currmax = nums[i];
			for (int j = i + 1; j < i + k; j++) {
				if (nums[j] > Currmax) {
					Currmax = nums[j];
				}
			}
			ans.push_back(Currmax);
		}
		return ans;
	}

	//solution 2:优先队列法，关键在于堆中最大值的更新：实际只有最大值在当前滑动窗的左侧，才会将其删除；所以优先队列中需要存入pair(数值，索引)
	vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
		int n = nums.size();
		priority_queue<pair<int, int>> q;
		vector<int> ans;
		//构建优先队列
		for (int i = 0; i < k; i++) {
			q.emplace(nums[i], i);
		}
		ans.push_back(q.top().first);		//放入第一个最大值
		//逐个考虑后面的元素
		for (int i = k; i < n; i++) {
			q.emplace(nums[i], i);	//先将新元素入堆
			//判断此时的最大值是不是在当前滑动窗里，一直处理到top()在滑动窗里
			while (q.top().second <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().first);
		}
		return ans;
	}

	//solution 3:单调队列，将一个窗内的元素按照索引由小到大压入队列，根据后面元素和队列尾部进行比较，将比当前元素小的值都删除，最终获得一个单调递减的队列
	vector<int>maxSlidingWindow3(vector<int>& nums, int k) {
		int n = nums.size();
		deque<int> q;		//双端队列，存的是索引，但是这些索引对应的值是单调递减的
		for (int i = 0; i < k; i++) {
			//判断是不是比前面的大，一直pop_back到空或者比当前值大的位置
			while (!q.empty() && nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		//存入第一个窗的最大值
		vector<int> ans = { nums[q.front()] };
		//逐个考虑后面的元素
		for (int i = k; i < n; i++) {
			while (!q.empty() && nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
			//取窗内最大值，但是必须要考虑该值在不在窗内
			while (q.front() <= i - k) {
				q.pop_front();
			}
			ans.push_back(nums[q.front()]);
		}
		return ans;
	}

	//solution4: 分块+预处理，难点在于怎样预处理bing
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> prefixMax(n), suffixMax(n);
		//处理前缀最大值，必须由前向后处理，因为递推式
		for (int i = 0; i < n; i++) {
			if (i % k == 0) {
				prefixMax[i] = nums[i];
			}
			else {
				prefixMax[i] = max(prefixMax[i - 1], nums[i]);		//注意这里是prefixMax[i-1]
			}
		}
		//处理后缀最大值，必须要由后向前处理，因为递推式
		for (int i = n - 1 ; i >= 0; i--) {
			if (i == n - 1 || (i + 1) % k == 0) {
				suffixMax[i] = nums[i];
			}
			else {
				suffixMax[i] = max(suffixMax[i + 1], nums[i]);		//注意这里是suffixMax[i+1]
			}
		}

		vector<int> ans;
		for (int i = 0; i < n - k; i++) {
			ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));		//注意此处是后缀取i，前缀取i+k-1
		}
		return ans;
	}
};
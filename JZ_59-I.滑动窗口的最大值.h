//����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ.
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//����1��������
//�Ľ�1����������˫�˶����Ż�������һ��Ԫ�ص�ʱ��ͨ���ȽϾͿ��Ը������ֵ��ɾ��Ԫ�ص�ʱ����ǡ�������ֵ���͵ñ������ڵõ��µ����ֵ��������
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

//����2�����ȶ���
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
            //ֻҪpop�����ڴ����е�Ԫ�ؼ���
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

//����3��˫�˶���ʵ�ֵġ��������С�����˳�򵥵��ݼ���ʱ�临�Ӷ�O(N)
//�����ڵ�Ԫ��ά����һ�������ݼ����У���ô���ֵһ���ڶ��ף�
//�����ƶ����µ�Ԫ�����β���бȽϣ�����ȶ�βС��ֱ�ӷ��ڶ�β������ȶ�β���Ҫ������β�������Ƚϣ�ֱ�����㵥���ݼ����ص㣬���߶���Ϊ��
//�����б����������������Ԫ�ر������������ж��Ƿ��ڴ���
class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        deque<int> Q;       //����洢����nums�е���������Ԫ�ر���
        for (int i = 0; i < k; i++) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i);
        }
        vector<int> ans = { nums[Q.front()] };
        for (int i = k; i < nums.size(); i++) {
            while (!Q.empty() && nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i);

            //Ҫ�����ڴ��ڵ�Ԫ��pop��ȥ
            while (Q.front() <= i - k) Q.pop_front();
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};
#include<vector>
#include<queue>
using namespace std;

//排序，时间复杂度O(NlogN)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            vec[i] = arr[i];
        }
        return vec;
    }
};

//利用堆，时间复杂度O(NlogK)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        if (k == arr.size()) return arr;
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};
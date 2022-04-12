//����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s�����������һ�Լ��ɡ�
#include<vector>
#include<unordered_set>
using namespace std;

//����1������hash���ռ临�Ӷ�O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 1) return {};
        unordered_set<int> q;
        for (int i = 0; i < n; i++) {
            if (q.count(target - nums[i]) != 0)
                return { nums[i], target - nums[i] };
            q.insert(nums[i]);
        }
        return {};
    }
};

//����2�����������Ѿ�������ص㣬����˫ָ�������м��ƶ�
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 1) return {};
        int left = 0, right = n - 1;
        while (left < right) {
            int tmp = nums[left] + nums[right];     //���ڿ���������������Ҫͬ��ӵĽ��ȥ�Ƚϴ�С
            if (tmp == target) return { nums[left], nums[right] };
            else if (tmp > target) right--;
            else left++;
        }
        return {};
    }
};
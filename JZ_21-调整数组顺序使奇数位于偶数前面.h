//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����������������ǰ�벿�֣�����ż��������ĺ�벿�֡�
#include<vector>
using namespace std;

//˫ָ�뷨���ռ临�Ӷ�O(N)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[right--] = nums[i];
            }
            else {
                ans[left++] = nums[i];
            }
        }
        return ans;
    }
};

//ԭ�ؽ���1
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] % 2 == 0) {
                swap(nums[left], nums[right]);
                right--;
            }
            else left++;
        }
        return nums;
    }
};

//ԭ�ؽ���2��������ŵ�˼��
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < n && nums[left] % 2 == 1) left++;
            while (right >= 0 && nums[right] % 2 == 0) right--;
            if (left > right) break;
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};
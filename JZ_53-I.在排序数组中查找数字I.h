//ͳ��һ�����������������г��ֵĴ�����
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//��������
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        
        for (const int& it : nums) {
            if (it == target) count++;
        }
        return count;
    }
};

//���ֲ���1
class Solution2 {
private:
    int count;
public:
    //����ҿ�����
    void binSearch(vector<int>& nums, int left, int right, int target) {
        if (left == right - 1) {
            if (nums[left] == target) count++;
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) binSearch(nums, left, mid, target);
        else if (nums[mid] < target) binSearch(nums, mid + 1, right, target);
        else {
            count++;
            binSearch(nums, left, mid, target);
            binSearch(nums, mid + 1, right, target);
        }
    }

    int search(vector<int>& nums, int target) {
        count = 0;
        binSearch(nums, 0, nums.size(), target);
        return count;
    }
};

//���ֲ���2���ҵ���һ������target ��λ�á���һ������target��λ��
class Solution3 {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;      //���浱ǰ�Ľ���������������������ʱ���Ҳ���
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);     //true��ʾ����߽�
        int rightIdx = binarySearch(nums, target, false) - 1;   //false��ʾ���ұ߽�
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return rightIdx - leftIdx + 1;
        }
        cout << leftIdx << ";" << rightIdx;
        return 0;
    }
};

//�����㷨��
class Solution4 {
public:
    int search(vector<int>& nums, int target) {
        const auto res = equal_range(nums.begin(), nums.end(), target);
        return res.second - res.first;
    }
};
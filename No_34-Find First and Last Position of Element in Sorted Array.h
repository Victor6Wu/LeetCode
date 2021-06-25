//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:ѭ��������ʱ�临�Ӷ�O(n)
	vector<int> searchRange1(vector<int>& nums, int target) {
		int start_ptr = -1, end_ptr = -1;
		int count = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target && count == 0) {
				start_ptr = i;
				++count;
			}
			else if (nums[i] == target) {
				++count;
			}
		}
		if (start_ptr != -1) {
			end_ptr = start_ptr + count - 1;
		}
		
		return { start_ptr,end_ptr };
	}

	//solution 2:���ֲ��ң�ʱ�临�Ӷ�O(logn)��˼·��Ҫ�ҵ���ʵ���ǵ�һ�� >=target ��λ�ã��͵�һ�� >target ��λ��
	int binarySearch(vector<int>& nums, int target, bool lower) {	//lower��һ����ʶ������ʾ����>=����>target��λ��
		int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size(); //ans��ʼֵΪnums.size(),��searchRange����Ҫ�����Ƿ��޸�
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] > target || (lower && nums[mid] >= target)) {			//���۴��ڵ��ڻ��Ǵ��ڣ�Ҫ������������
				right = mid - 1;
				ans = mid;
			}
			else {			//С�ڵ��ڻ���С�ڣ���Ҫ������������
				left = mid + 1;
			}
		}
		return ans;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int left_index = binarySearch(nums, target, true);				//�ҵ���һ�����ڵ��ڵ�λ��
		int right_index = binarySearch(nums, target, false) - 1;		//������ĺ����ҵ���һ�����ڵ�λ��
		//�ж�����
		if (left_index <= right_index && right_index < nums.size() && nums[left_index] == target && nums[right_index] == target) {
			return {left_index,right_index};
		}
		return { -1,-1 };
	}
};
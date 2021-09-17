//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	//solution :����sort����
	int findKthLargest1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}

	//solution 1:��д����
	void quickSort1(vector<int>& nums, int lo, int hi) {			//���ŵĵݹ����
		if (hi <= lo) return;
		int j = partition1(nums, lo, hi);
		quickSort1(nums, lo, j - 1);
		quickSort1(nums, j + 1, hi);
	 }
	//�����з�
	int partition1(vector<int>& nums, int lo, int hi) {
		int left = lo, right = hi;		//��ָ���lo��ʼ����ָ���hi��ʼ
		int element = nums[lo];
		while (left < right) {
			while (nums[left] <= element) {		//�˴����� <= ������left���Դ�lo��ʼ
				if (left == hi) break;
				left++;
			}
			while (nums[right] > element) {
				if (right == lo) break;
				right--;
			}
			//�ж�����ָ���Ƿ�����
			if (left >= right) {
				break;
			}
			swap(nums[left], nums[right]);		//�ڻ�û����ǰ����������ָ����ָԪ��
		}
		//����ָ�������󣬽�element���ں��ʵ�λ��
		swap(nums[lo], nums[right]);	//ע����������right��������Ϊ����ǰ��Ĳ�����right��ָ��Ԫ���� <= element ��
		return right;
	}

	int findKthLargest1(vector<int>& nums, int k) {
		quickSort1(nums, 0, nums.size() - 1);
		return nums[nums.size() - k];
	}

	//solution 2:���ŸĽ���������ĿҪ���K����;�ҵ������˳�
	void quickSort2(vector<int>& nums, int lo, int hi, int k) {			//���ŵĵݹ����
		if (hi <= lo) return ;
		int j = partition2(nums, lo, hi);
		if (j != nums.size() - k) {
			quickSort2(nums, lo, j - 1, k);
			quickSort2(nums, j + 1, hi, k);
		}
		else return;
	}
	//�����з�
	int partition2(vector<int>& nums, int lo, int hi) {
		int left = lo, right = hi;		//��ָ���lo��ʼ����ָ���hi��ʼ
		int element = nums[lo];
		while (left < right) {
			while (nums[left] <= element) {		//�˴����� <= ������left���Դ�lo��ʼ
				if (left == hi) break;
				left++;
			}
			while (nums[right] > element) {
				if (right == lo) break;
				right--;
			}
			//�ж�����ָ���Ƿ�����
			if (left >= right) {
				break;
			}
			swap(nums[left], nums[right]);		//�ڻ�û����ǰ����������ָ����ָԪ��
		}
		//����ָ�������󣬽�element���ں��ʵ�λ��
		swap(nums[lo], nums[right]);	//ע����������right��������Ϊ����ǰ��Ĳ�����right��ָ��Ԫ���� <= element ��
		return right;
	}

	int findKthLargest2(vector<int>& nums, int k) {
		quickSort2(nums, 0, nums.size() - 1, k);
		return nums[nums.size() - k];
	}

	//solution 3:���ڶѣ�����ѣ�����K��ɾ�����ڵ㣬����ֱ����priority_queue��ҲҪ���Լ�д	
	int findKthLargest3(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, less<int>> q;
		for (const auto& x : nums) {
			q.push(x);
		}
		for (int i = 1; i < k; i++) {
			q.pop();
		}
		return q.top();
	}

	//solution 4:����С���ѣ����ƶѵĹ�ģʼ��ΪK
	int findKthLargest4(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < k; i++) {
			q.push(nums[i]);
		}
		for (int i = k; i < nums.size(); i++) {
			if (nums[i] > q.top()) {
				q.pop();
				q.push(nums[i]);
			}
		}
		return q.top();
	}
};
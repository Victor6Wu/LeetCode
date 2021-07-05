//You are given two integer arrays nums1and nums2, sorted in non - decreasing order, and two integers mand n, 
//representing the number of elements in nums1and nums2 respectively.
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:�Ⱥϲ�������
	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m; i < nums1.size(); ++i) {
			nums1[i] = nums2[i-m];
		}
		sort(nums1.begin(), nums1.end());
	}

	//solution 2:˫ָ�뷨������nums1��nums2�Ѿ����������
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = 0, p2 = 0;
		vector<int> sorted;
		while (p1 < m || p2 < n) {
			if (p1 == m) sorted.push_back(nums2[p2++]);
			else if (p2 == n) sorted.push_back(nums1[p1++]);
			else if (nums1[p1] < nums2[p2]) sorted.push_back(nums1[p1++]);
			else sorted.push_back(nums2[p2++]);
		}
		for (int i = 0; i < m + n; ++i) {
			nums1[i] = sorted[i];
		}
	}

	//solution 3:����˫ָ�룬��sln2�Ļ����ϣ��Ӻ���ǰ�Ƚϴ�С��������������һ����ʱ������ռ�
	void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1;
		int fill_ptr = nums1.size() - 1;			//��ʾ�Ӻ���ǰ�����λ��
		while (i >= 0 || j >= 0) {
			if (i == -1) nums1[fill_ptr] = nums2[j--];
			else if (j == -1) nums1[fill_ptr] = nums1[i--];
			else if (nums1[i] > nums2[j]) nums1[fill_ptr] = nums1[i--];
			else nums1[fill_ptr] = nums2[j--];
			fill_ptr--;
		}
	}
};
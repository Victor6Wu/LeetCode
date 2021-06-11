#pragma once
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
#include<vector>
#include<algorithm>
#include<Math.h>
using namespace std;

class Solution {
public:
	//solution 1: 先合并再排序，直接锁定中位数
	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(); int n = nums2.size();
		for (int i = 0; i < n; ++i)
			nums1.push_back(nums2[i]);
		sort(nums1.begin(), nums1.end());
		int median = (m + n) / 2;
		return	(m + n) % 2 == 0 ? (double(nums1[median]) + double(nums1[median - 1])) / 2.0 : nums1[median];
	}

	//solution 2: 双指针，交替查找直到找到中间一个或两个数
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(); int n = nums2.size();
		int i = 0, j = 0;
		int sum = m + n;
		int compare = (sum - 1) / 2;
		//先进行循环
		for (; i < m && j < n;) {
			if (i + j == compare) break;
			if (nums1[i] <= nums2[j])
				++i;
			else
				++j;
		}
		//长度和为奇数的情况
		if (sum % 2 != 0) {
			if (i == m) return nums2[compare - m];
			else if (j == n) return nums1[compare - n];
			return nums1[i] <= nums2[j] ? nums1[i] : nums2[j];
		}
		//长度和为偶数的情况
		else {
			//先判断是否有一个数组已经考察完毕
			if (i == m) return (nums2[compare - m] + nums2[compare - m + 1]) / 2.0;
			else if (j == n) return (nums1[compare - n] + nums1[compare - n + 1]) / 2.0;
			//若两个数组均没考察完毕
			else {
				int n1 = 0, n2 = 0;
				if (nums1[i] <= nums2[j]) {
					n1 = nums1[i];
					++i;
				}
				else {
					n1 = nums2[j];
					++j;
				}
				//得到第一个数后再判断一下是否有一个数组考察完毕
				if (i == m)
					n2 = nums2[j];
				else if (j == n)
					n2 = nums1[i];
				//若无，再寻找第二个数 
				else {
					if (nums1[i] <= nums2[j])
						n2 = nums1[i];
					else
						n2 = nums2[j];
				}
				return (n1 + n2) / 2.0;
			}
		}
	}

	//solution 3: 划分数组，再二分查找法
	double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
		 }

		int m = nums1.size();
		int n = nums2.size();

		//建立一个等式关系，表示分割线左侧的元素个数,无论总数为奇还是偶数
		int totalLeft = (m + n + 1) / 2;

		//在相对短的数组nums1中查找分割线，查找方式为二分查找,不断更新查找区间
		int left = 0;
		int right = m;

		while (left < right) {
			int i = left + (right - left + 1) / 2;	//构造nums1的分割线     !必须保证right-left要+1，否则会导致nums1[i-1]溢出
			int j = totalLeft - i;				//构造nums2的分割线
			if (nums1[i - 1] > nums2[j]) {		//判断nums1分割线左侧的元素是否大于nums2分割线右侧的元素
				right = i - 1;					//大于，说明nums1分割线位置偏大（右），要往小（左）更新
			}
			else {
				left = i;						//不大于，说明nums1分割线位置偏小（左），要往大（右）更新
			}
		}

		//分割线确定完毕后，需要奇偶对分割线左右共四个元素进行比较，还要注意数组下标越界的问题
		int i = left;
		int j = totalLeft - i;
		int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
		int nums1RightMin = i == m ? INT_MAX : nums1[i];
		int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
		int nums2RightMin = j == n ? INT_MAX : nums2[j];

		if ((m + n) % 2 == 1) {
			return max(nums1LeftMax, nums2LeftMax);
		}
		else {
			cout << max(nums1LeftMax, nums2LeftMax) << endl;
			cout << min(nums1RightMin, nums1RightMin) << endl;
			return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
		}
	}
};
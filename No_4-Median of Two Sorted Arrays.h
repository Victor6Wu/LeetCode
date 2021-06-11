#pragma once
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
#include<vector>
#include<algorithm>
#include<Math.h>
using namespace std;

class Solution {
public:
	//solution 1: �Ⱥϲ�������ֱ��������λ��
	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(); int n = nums2.size();
		for (int i = 0; i < n; ++i)
			nums1.push_back(nums2[i]);
		sort(nums1.begin(), nums1.end());
		int median = (m + n) / 2;
		return	(m + n) % 2 == 0 ? (double(nums1[median]) + double(nums1[median - 1])) / 2.0 : nums1[median];
	}

	//solution 2: ˫ָ�룬�������ֱ���ҵ��м�һ����������
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(); int n = nums2.size();
		int i = 0, j = 0;
		int sum = m + n;
		int compare = (sum - 1) / 2;
		//�Ƚ���ѭ��
		for (; i < m && j < n;) {
			if (i + j == compare) break;
			if (nums1[i] <= nums2[j])
				++i;
			else
				++j;
		}
		//���Ⱥ�Ϊ���������
		if (sum % 2 != 0) {
			if (i == m) return nums2[compare - m];
			else if (j == n) return nums1[compare - n];
			return nums1[i] <= nums2[j] ? nums1[i] : nums2[j];
		}
		//���Ⱥ�Ϊż�������
		else {
			//���ж��Ƿ���һ�������Ѿ��������
			if (i == m) return (nums2[compare - m] + nums2[compare - m + 1]) / 2.0;
			else if (j == n) return (nums1[compare - n] + nums1[compare - n + 1]) / 2.0;
			//�����������û�������
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
				//�õ���һ���������ж�һ���Ƿ���һ�����鿼�����
				if (i == m)
					n2 = nums2[j];
				else if (j == n)
					n2 = nums1[i];
				//���ޣ���Ѱ�ҵڶ����� 
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

	//solution 3: �������飬�ٶ��ֲ��ҷ�
	double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
		 }

		int m = nums1.size();
		int n = nums2.size();

		//����һ����ʽ��ϵ����ʾ�ָ�������Ԫ�ظ���,��������Ϊ�滹��ż��
		int totalLeft = (m + n + 1) / 2;

		//����Զ̵�����nums1�в��ҷָ��ߣ����ҷ�ʽΪ���ֲ���,���ϸ��²�������
		int left = 0;
		int right = m;

		while (left < right) {
			int i = left + (right - left + 1) / 2;	//����nums1�ķָ���     !���뱣֤right-leftҪ+1������ᵼ��nums1[i-1]���
			int j = totalLeft - i;				//����nums2�ķָ���
			if (nums1[i - 1] > nums2[j]) {		//�ж�nums1�ָ�������Ԫ���Ƿ����nums2�ָ����Ҳ��Ԫ��
				right = i - 1;					//���ڣ�˵��nums1�ָ���λ��ƫ���ң���Ҫ��С���󣩸���
			}
			else {
				left = i;						//�����ڣ�˵��nums1�ָ���λ��ƫС���󣩣�Ҫ�����ң�����
			}
		}

		//�ָ���ȷ����Ϻ���Ҫ��ż�Էָ������ҹ��ĸ�Ԫ�ؽ��бȽϣ���Ҫע�������±�Խ�������
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
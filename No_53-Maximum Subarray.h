//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:̰���㷨����ǰָ����ָԪ��֮ͬǰԪ�صĺ�С��0��������ǰԪ�ؼ���ǰ�����У�����һ�����¿�ʼ��
	int maxSubArray(vector<int>& nums) {
		int MaxSum = nums[0], CurrSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			CurrSum += nums[i];
			MaxSum = max(MaxSum, CurrSum);
			if (CurrSum <= 0) {
				CurrSum = 0;
			}
		}
		return MaxSum;
	}

	//solution 2:��̬�滮���ο�̰���㷨��˼�룬������һ���ر�С�ĸ�������ͻ��Ϊ�������ս�֮ǰ�������ַ�
	int maxSubArray(vector<int>& nums) {
		int pre = 0, maxAns = nums[0];
		for (const auto& x : nums) {
			pre = max(pre + x, x);		//ÿ��pre<=0��ʱ��pre��ӵ�ǰ��x�ַ����¿�ʼ����
			maxAns = max(maxAns, pre);
		}
		return maxAns;
	}
};
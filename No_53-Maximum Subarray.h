//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:̰���㷨����ǰָ����ָԪ��֮ͬǰԪ�صĺ�С��0��������ǰԪ�ؼ���ǰ�����У�����һ�����¿�ʼ��
	int maxSubArray(vector<int>& nums) {
		//�и��ؼ��㣬MaxSumҪ��ʼΪnums[0]�������Գ�ʼ��Ϊ0����������ȫ������������
		int MaxSum = nums[0], CurrSum = 0;		//ά������������һ����ʾ���ս����һ����ʾ���������н׶��Ե���ͽ��
		for (int i = 0; i < nums.size(); i++) {
			CurrSum += nums[i];
			MaxSum = max(MaxSum, CurrSum);
			//ÿ������һ������ʹ�ý׶�����ͽ����ɷ��������Ǿ����¼���
			if (CurrSum <= 0) {
				CurrSum = 0;
			}
		}
		return MaxSum;
	}

	//solution 2:��̬�滮���ο�̰���㷨��˼�룬������һ���ر�С�ĸ�������ͻ��Ϊ�������ս�֮ǰ�������ַ�
	int maxSubArray(vector<int>& nums) {
		int pre = 0, maxAns = nums[0];		//pre��ʾ֮ǰ����������
		for (const auto& x : nums) {
			pre = max(pre + x, x);		//ÿ��pre<=0��ʱ��pre��ӵ�ǰ��x�ַ����¿�ʼ����
			maxAns = max(maxAns, pre);
		}
		return maxAns;
	}
};
//��̬�滮
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> dp(nums.size(), 0); // dp[i]��ʾ����i֮ǰ��������������к�
		dp[0] = nums[0];
		int result = dp[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]); // ״̬ת�ƹ�ʽ
			if (dp[i] > result) result = dp[i]; // result ����dp[i]�����ֵ
		}
		return result;
	}
};
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
//If the array contains less than two elements, return 0.
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1 :��sort����
	int maximumGap1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0;
		int n = nums.size();
		if (n < 2) {
			return ans;
		}
		else {
			for (int i = 1; i < n; i++) {
				int temp = nums[i] - nums[i - 1];
				ans = max(ans, temp);
			}
		}
		return ans;
	}

	//solution 2:��������ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(N)�����ø�λ��ʮλ��...���ν��з�Ͱ����װ����
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return 0;
		}
		int divisor = 1;		//������1��ʼ��10��1000......
		vector<int> buf(n);		//����ʢ����������
		int maxVal = *max_element(nums.begin(), nums.end());
		while (maxVal >= divisor) {			//�������ܳ���������������û������
			vector<int> count(10);			//����ͳ�Ƶ�ǰλΪ0-9��Ͱ�����ֵĸ���

			//ͳ�Ƹ�Ͱ�����ָ���
			for (int i = 0; i < n; i++) {
				int digit = (nums[i] / divisor) % 10;		//�õ���ǰλ������
				count[digit]++;
			}

			//����Ҫ��һ������cout�ڴ�ǰ��������ۼӣ����ϵ���������������
			for (int i = 1; i < 10; i++) {
				count[i] += count[i - 1];
			}

			//����cout�����Ͱ�ڵ����ֽ������飬�Ӻ���ǰ���У������Ӱ��֮ǰ�Ѿ��źõ�˳��
			for (int i = n - 1; i >= 0; i--) {
				int digit = (nums[i] / divisor) % 10;
				buf[count[digit] - 1] = nums[i];		//count[digit] - 1ȷ����ǰ�������������е�����
				count[digit]--;
			}

			copy(buf.begin(), buf.end(), nums.begin());		//�ڸ���ʮ����...λ�ϴ�С���򣬸���ԭʼ����
			divisor *= 10;
		}

		//�ж����Gap
		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans = max(ans, nums[i] - nums[i - 1]);
		}
		return ans;
	}
};
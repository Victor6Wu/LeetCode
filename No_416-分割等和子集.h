//����һ�� ֻ���������� �� �ǿ� ���� nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

//��̬�滮����1����ά����
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {		//���ֻ��һ��Ԫ�أ��϶����ܻ��ֳ�
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxNum = *max_element(nums.begin(), nums.end());		//��ȡ���Ԫ��
		//sumΪ��������false��sum/2<maxNum�򷵻�false
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		if (maxNum > target) return false;
		vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
		//��ʼ���߽�����
		for (int i = 0; i < n; i++) {
			dp[i][0] = true;	//��һ�о�Ϊtrue
		}
		dp[0][nums[0]] = true;	//��һ����ֻ�иպõ���nums[0]��λ��Ϊtrue
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= target; j++) {
				if (j >= nums[i]) {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n - 1][target];
	}
};

//��̬�滮����1��һά����
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {		//���ֻ��һ��Ԫ�أ��϶����ܻ��ֳ�
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxNum = *max_element(nums.begin(), nums.end());		//��ȡ���Ԫ��
		//sumΪ��������false��sum/2<maxNum�򷵻�false
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		if (maxNum > target) return false;
		vector<bool> dp(target + 1, false);
		//��ʼ���߽�����
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = target; j >= nums[i]; j--) {		//�Ӵ�С������������ֹ��������������ʱ����Ϊ���������Ĳ����൱��ά��ԭ��dp[j]
				dp[j] = dp[j] || dp[j - nums[i]];
			}
		}
		return dp[target];
	}
};

//��̬�滮����2����������¼�����ǿ��Ǽ�ֵ��ֻ����������Ʒ�ļ�ֵ������Ʒ����������ôÿ��dp[j]��ȡ����ֵ���ɣ���Ϊdp[j]�����ֵ���ᳬ��j
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {		//���ֻ��һ��Ԫ�أ��϶����ܻ��ֳ�
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxNum = *max_element(nums.begin(), nums.end());		//��ȡ���Ԫ��
		//sumΪ��������false��sum/2<maxNum�򷵻�false
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		if (maxNum > target) return false;
		//�����Ŀ���ļ�ֵ������������ô��0�±궼��ʼ��Ϊ0�Ϳ����ˣ������Ŀ���ļ�ֵ�и�������ô��0�±��Ҫ��ʼ��Ϊ�����
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = target; j >= nums[i]; j--) {		//�Ӵ�С������������ֹ��������������ʱ����Ϊ���������Ĳ����൱��ά��ԭ��dp[j]
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);			//�뷽��1Ψһ��ͬ�ľ���dp�ĺ��壬Ҳ���������ڴ˴�
			}
		}
		//����ж�һ��dp[target]�ܻ�õ�����ֵ�ǲ��Ǹո���target
		return dp[target] == target ? true : false;
	}
};
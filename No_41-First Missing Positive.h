//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) timeand uses constant extra space.
#include<vector>
#include<algorithm>
using namespace std;

//solution 1:�Ա���룬�õ������� 
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0;
		while (i < nums.size() && nums[i] <= 0) {
			i++;
		}
		int num = 1;
		while (i < nums.size() && num == nums[i]) {
			i++;
			if (i < nums.size() && nums[i] == nums[i - 1]) {
				continue;
			}
			num++;
		}
		return num;
	}
};

//solution 2:���ù�ϣ���˼�룬������������λ�õ���������ʾ��1��n�������ֵĳ������
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//��һ�α���ǰӦ��Ҫ���ж���������û�г���1�������������ȫ���Ǵ���n�������������
		//��һ�α�������С�ڵ���0���ʹ���n��������Ϊ1��������������鶼��������
		int sign = 0;		//�ж�����������1�ı�־
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) sign = 1;
			if (nums[i] <= 0) {
				nums[i] = 1;
			}
			else if (nums[i] > nums.size()) {
				nums[i] = 1;
			}
		}
		if (sign == 0) return 1;		//�����־��Ϊ0��˵��������û��1�����ؼ��� 

		//�ڶ��α������������ִ�С����Ӧ������������Ϊ�������Ա��������ֳ��ֹ�
		//Ҫע�����ظ����ֵ����⣻ע�������Ǵ�0��ʼ������
		for (int i = 0; i < nums.size(); i++) {
			int num = abs(nums[i]);		//��Ϊ��λ�õ������ܱ���Ϊ����������ֻ������ֵ
			nums[num - 1] = -abs(nums[num - 1]);
		}

		//�����α�����Ѱ�������е�һ������������������û���������ʹ�������������ֵΪ��
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		//������Ǹ�����˵������պ��ǡ�1��n���������Ϊn+1
		return nums.size() + 1;
	}
};

//solution 2+:û��Ҫ������n������Ϊ1����ΪҲ�Ҳ�������Ӧ����������С�ڵ���0������Ϊn+1����
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//��һ�α����������еķ�������Ϊn+1
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= 0) {
				nums[i] = nums.size() + 1;
			}
		}

		//�ڶ��α������������ִ�С����Ӧ������������Ϊ�������Ա��������ֳ��ֹ�
		//Ҫע�����ظ����ֵ����⣻ע�������Ǵ�0��ʼ������
		for (int i = 0; i < nums.size(); i++) {
			int num = abs(nums[i]);		//��Ϊ��λ�õ������ܱ���Ϊ����������ֻ������ֵ
			if (num <= nums.size()) {
				nums[num - 1] = -abs(nums[num - 1]);
			}
		}

		//�����α�����Ѱ�������е�һ������������������û���������ʹ�������������ֵΪ��
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		//������Ǹ�����˵������պ��ǡ�1��n���������Ϊn+1
		return nums.size() + 1;
	}
};

//solution 3:�û����������ַŵ�Ӧ����λ�ã�������[1,2,...N]����ʽ��ֱ����ǰ������������[1,N]֮�䣬�ر�ע����ѭ���������һ��N���������Ҳ��ѭ��N��
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		//�ҵ���һ����������ֵ��������
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};
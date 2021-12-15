//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
#include<vector>
#include<algorithm>
using namespace std;

//solution1:���No_31�ֵ����˼·
class Solution1 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size() - 2;
		vector<vector<int>> res;
		res.push_back(nums);
		bool sign = true;
		while (sign) {
			int i = n;
			while (i >= 0 && nums[i] >= nums[i + 1]) {
				i--;
			}
			if (i >= 0) {
				int j = n + 1;
				while (j > 0 && nums[i] >= nums[j]) {
					j--;
				}
				swap(nums[i], nums[j]);
				reverse(nums.begin() + i + 1, nums.end());
				res.push_back(nums);
			}
			else {
				sign = false;
			}
		}
		return res;
	}
};

//solution2:���ݷ�����nums��Ԫ����vector����ؼ�������ʼ��ά������һ�����飬����Ҫ����ǰ׼���������׼���λ�ô��������н�����
//���Ѿ����˵���Ų���������࣬�Ҳ��Ǵ������
class Solution2 {
public:
	//first��ʾ��ǰ��Ҫ��Ŀ�
	void backtrack(vector<vector<int>>& res, vector<int>& nums, int first, int len) {
		if (first == len) {
			res.push_back(nums);
			return;
		}
		//��firstλ�ü�֮���ÿ����ѭ���������뵱ǰ��firstλ��
		for (int i = first; i < len; i++) {			//����ؼ���һ�����ڣ�i�Ǵ�first��ʼ�ģ���Ϊfirst��ǰ��λ���Ѿ�������ˣ���ͨ��swap��������Щ��������λ������
			//��̬ά������
			swap(nums[i], nums[first]);
			//����������һ��λ��
			backtrack(res, nums, first + 1, len);
			//����i����first�Ĳ���������i+1����first
			swap(nums[i], nums[first]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		backtrack(res, nums, 0, (int)nums.size());
		return res;
	}
};
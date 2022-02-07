//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
#include<vector>
#include<algorithm>
using namespace std;

//solution1:���No_31�ֵ����˼·����һ�������ֵ�����ǲ��ϵؽ������Ų����λ��С����Ų����λ��
class Solution1 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size() - 2;
		vector<vector<int>> res;
		res.push_back(nums);
		bool sign = true;
		while (sign) {
			int i = n;		//�Ӻ���ǰ�ң��ҵ��Ǹ�����������������Ƶ�λ��
			while (i >= 0 && nums[i] >= nums[i + 1]) {
				i--;
			}
			if (i >= 0) {
				int j = n + 1;
				while (j > 0 && nums[i] >= nums[j]) {		//���ǴӺ���ǰ�ң��ҵ��պñ�iλ�õ��������
					j--;
				}
				swap(nums[i], nums[j]);
				reverse(nums.begin() + i + 1, nums.end());	//���ź���һ���֣�ʹ�������������
				res.push_back(nums);
			}
			else {			//����������ʵݼ�����ʱ�Ѿ��������ֵ��򣬴���i���ҵ�-1���˳�����
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

//������д���룬������û���ظ�ֵ��������ȫ�������ζ�Ŷ����е�����������ȫ����
class Solution {
private:
	vector<vector<int>> result;
	vector<int> tmp;
public:
	void backtracking(vector<int>& nums, vector<bool> used) {
		if (tmp.size() == nums.size()) {
			result.push_back(tmp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!used[i]) {
				used[i] = true;
				tmp.push_back(nums[i]);
				backtracking(nums, used);
				tmp.pop_back();
				used[i] = false;
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> used(nums.size(), false);		//��ʵ��ά��������û�б��ù�
		backtracking(nums, used);
		return result;
	}
};
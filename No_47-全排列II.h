//����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�
#include<vector>
#include<algorithm>
using namespace std;

//����No_46���ֵ��򷽷�����⣬���ÿ���ʲô�ظ�������
class Solution1 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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

//���ݷ�1����No_46�Ļ�����Ҫ����һ��ͬ��ȥ�صĲ���
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

		vector<bool> usedNum(21, false);		//ͬ��ȥ�أ�ע��������ó�true�󲻻������û�false
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] || usedNum[nums[i] + 10]) {
				continue;
			}
			usedNum[nums[i] + 10] = true;
			used[i] = true;
			tmp.push_back(nums[i]);
			backtracking(nums, used);
			tmp.pop_back();
			used[i] = false;		
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool> used(nums.size(), false);		//ά��������û�б��ù�������ϵ�ȥ��	
		backtracking(nums, used);				
		return result;
	}
};

//���ݷ�2���ڵݹ�֮���Ͷ��������������������Ҫͨ��ά��usedNum����ķ�ʽҲ��ʵ��ͬ��ȥ��
class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<bool>& used) {
		// ��ʱ˵���ҵ���һ��
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			// used[i - 1] == true��˵��ͬһ��֦nums[i - 1]ʹ�ù�
			// used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
			// ���ͬһ����nums[i - 1]ʹ�ù���ֱ��������ͬһ��֦ʹ�ù�û��ϵ
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {//��������used[i - 1] == false����Ӱ������ϵĵݹ飨����֦��
				continue;
			}
			if (used[i] == false) {
				used[i] = true;
				path.push_back(nums[i]);
				backtracking(nums, used);
				path.pop_back();
				used[i] = false;
			}
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		result.clear();
		path.clear();
		sort(nums.begin(), nums.end()); // ����
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return result;
	}
};
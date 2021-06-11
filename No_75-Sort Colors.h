//ԭ�ض��������򣬲���ʹ��sort����
#include<vector>
using namespace std;
class Solution {
public:
	//solution 1:��������
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		bool sorted = false;
		for (int i = 0; (i < nums.size()) && (sorted == false); ++i) {
			sorted = true;
			for (int j = 1; j < n; ++j) {
				if (nums[j - 1] > nums[j]) {
					int temp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = temp;
					sorted = false;
				}
			}
			n--;
		}
	}

	//solution 2��˫ָ��,ѭ�����Σ���һ�ΰ�0������ǰ�棬�ڶ��ΰ�1����0�����λ��
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0;
		while (j < nums.size()) {
			if (nums[j] == 0) {
				swap(nums[i], nums[j]);
				++i;
			}
			++j;
		}
		j = i;
		while (j < nums.size()) {
			if (nums[j] == 1) {
				swap(nums[i], nums[j]);
				++i;
			}
			++j;
		}
	}
};


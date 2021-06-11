//Given an array nums and a value val, remove all instances of that value in-place and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1:ԭ��ɾ����
	int removeElement1(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		for (auto i = nums.begin(); i != nums.end(); ) {
			if (*i == val) {
				i = nums.erase(i);
			}
			else {
				++i;
			}
		}
		return nums.size();
	}

	//solution 2:���+����
	int removeElement2(vector<int>& nums, int val) {
		if (nums.size() == 0)	return 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == val) nums[i] = INT_MAX;
		}
		sort(nums.begin(), nums.end());
		int j = 0;
		while (j < nums.size() && nums[j] < INT_MAX) {
			++j;
		}
		return j;
	}

	//solution 3:˫ָ�뷨����ͷ��ʼ����ָ�룬һ�������ƶ�
	int removeElement(vector<int>& nums, int val) {
		int left = 0, n = nums.size();				//left��ʼֵΪ0����Ҫ����󷵻صľ���left
		for (int right = 0; right < n; ++right) {
			if (nums[right] != val) {
				nums[left] = nums[right];
				left++;
			}
		}
		return left;
	}

	//solution 4:˫ָ�뷨�Ż�,ָ�����β��ʼ�����м��ϣ������˷���3��һЩ���õ��ظ�����
	int removeElement(vector<int>& nums, int val) {
		int left = 0, right = nums.size();
		while (left < right) {
			if (nums[left] == val) {
				nums[left] = nums[right - 1];		//��ĩβ��ֵ��������ͷ������val��ֵ
				--right;							//��ʱleft���䣬����Ҫ�ж��µ�nums[left]�Ƿ���Ȼ����val
			}
			//��֤���в�����val��ֵ�����Է���left��࣬����val��ֵ��������left�Ҳ�
			else {
				++left;
			}
		}
		return left;
	}
};
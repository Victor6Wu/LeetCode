//Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:������ԭ��ɾ��
	int removeDuplicates1(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		for (auto begin = nums.begin(); begin != nums.end() - 1;)
		{
			if (*begin == *(begin + 1))
			{
				begin = nums.erase(begin);		//erase�᷵�ر�ɾ����������һ��������
			}
			else
			{
				++begin;
			}
		}

		return nums.size();
	}

	//solution 2:˫ָ�뷨������ָ�룬�����Ԫ�ظ���ǰ���Ԫ��
	int removeDuplicates2(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return n;
		int i = 0, j = 1;
		while (j < n) {
			if (nums[i] != nums[j]) {
				++i;
				nums[i] = nums[j];
				++j;
			}
			else {
				++j;
			}
		}
		return i + 1;
	}
};
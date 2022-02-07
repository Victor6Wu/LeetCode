//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return ;
		int slow = 0, fast = 1;
		while (fast < n) {
			if (nums[slow] != 0) {
				slow++;
				fast++;
			}
			else {
				if (nums[fast] != 0) {
					swap(nums[slow], nums[fast]);
				}
				else {
					fast++;
				}
			}
		}
		return;
	}
};
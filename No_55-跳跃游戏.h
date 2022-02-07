//����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
//�ж����Ƿ��ܹ��������һ���±ꡣ
#include<vector>
using namespace std;

//����1��û����һ����͵ݹ��䷶Χ�ڵĵ㣬��һ���ݹ飬���кܶ�㱻�ظ����ʣ���ʱ
class Solution {
public:
    bool jump(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) return true;
        int step = nums[index];
        if (step == 0) return false;
        bool sign = false;
        while (step > 0) {
            sign = (sign || jump(nums, index + step));
            step--;
        }
        return sign;
    }
    bool canJump(vector<int>& nums) {
        return jump(nums, 0);
    }
};

//����2�������Ŀ�ؼ������ڣ����þ�����ÿ�ξ����������������ǿ����Ƿ�Χ�����Ƿ�Χ��һ���ǿ����������ģ����ù�����ô����
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);    //����cover
            if (cover >= nums.size()) return true;
        }
        return false;
    }
};
//��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
//���ҳ�����������һ���ظ������֡�
#include<vector>
using namespace std;

class Solution1 {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> count(nums.size(), false);
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]]) {
                ans = nums[i];
                break;
            }
            count[nums[i]] = true;
        }
        return ans;
    }
};

//����2���ռ临�Ӷ�O(1)������ԭʼ��nums������Ϊ�洢���ֽ�������飬��Ϊ��Ŀ�����������е���������[0, n)
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            if (k < 0) k += n;      //k < 0 ˵��֮ǰ���λ��������Ӧ����ֵ���ֹ�������λ�õ�ֵ�ټ���n�����������Ӧ��λ��
            if (nums[k] < 0) return k;  //�������ظ�ʱ�򣬷��ʵ�nums[k]�ᷢ�����Ѿ�����Ϊ����
            nums[k] -= n;
        }

        return -1;
    }
};
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//�ؼ��ǣ����˽�ʲô���ֵ���
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;    //�ӵ����ڶ���Ԫ�ؿ�ʼ
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {       //�ɹ��ҵ���Ҫ�����Ľ�С����
            int j = nums.size() - 1;
            while (j > 0 && nums[i] >= nums[j]) {      //�Ӻ���ǰ�ҵ��պñ�nums[i]�ĵ�һ��Ԫ��
                j--;
            }
            swap(nums[i], nums[j]);
        }
        //��nums[i]֮���Ԫ�����������������Ϊ������Ĳ���Ҳ��Ȼ�ǽ������� ֱ��reverse����
        //���nums�����Ѿ������������i�����-1�����巭ת����
        reverse(nums.begin() + i + 1, nums.end());
    }
};
//
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

//̰�ķ����Ƚ����µ�һЩ������Ϊ�����ٿ����Ƿ���С�ķǸ����������෴����
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int startIndex = 0;
        //�ȰѾ����ܶ�ĸ�����Ϊ��
        while (startIndex < nums.size() && nums[startIndex] < 0 && k > 0) {
            nums[startIndex] = 0 - nums[startIndex];
            startIndex++;
            k--;
        }
        if (k > 0) {     //k��ʣ�������ʱ�Ѿ�û�и���
            sort(nums.begin(), nums.end());
            k = k % 2;
            if (k == 1) {
                nums[0] = 0 - nums[0];
                k--;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
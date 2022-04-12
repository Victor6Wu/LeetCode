//һ������Ϊn - 1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0��n - 1֮�ڡ�
//�ڷ�Χ0��n - 1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�
#include<vector>
using namespace std;

//����һ�飬ʱ�临�Ӷ�O(N)
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] != 0) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) continue;
            return nums[i - 1] + 1;
        }
        return n;
    }
};

//���ַ����������⣬������Էֳ������֣���������nums[i] == i; ��������nums[i] != i
//ֻҪ���ҵ���������ĵ�һ��Ԫ�ض�Ӧ���������������ʱ�临�Ӷ�O��logN��
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid) left = mid + 1;   //�����ǰλ�û���nums[i] == i��˵���������黹���ұ�
            else right = mid - 1;       //���򣬴�ʱ�Ѿ���������������
        }
        return left;
    }
};
//����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����
#include<vector>
#include<algorithm>
using namespace std;

//����1��ƽ������������ʱ�临�Ӷ�O(nlogn)
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

//����2��˫ָ�뷨���ҵ������ֽ��ߣ����м�����ͷ�ֱ�Ƚϴ�С��������������
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int divide = 0;             //�����ֽ���
        for (; divide < nums.size(); divide++) {
            if (nums[divide] >= 0) {
                break;
            }
        }
        int i = divide - 1, j = divide;
        vector<int> ans;
        while (i >= 0 || j < nums.size()) {
            if (i < 0) {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
            else if (j >= nums.size()) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else if ((nums[i] * nums[i]) < (nums[j] * nums[j])) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return ans;
    }
};

//����3��˫ָ�뷨�����������м�ۼ�����˭�󣬰Ѵ�������������
class Solution3 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
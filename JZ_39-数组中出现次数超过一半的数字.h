//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//����
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//���ù�ϣ��
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        int n = nums.size();
        for (const int& it : nums) {
            table[it]++;
            if (table[it] > n / 2) return it;
        }
        return 0;
    }
};

//ͶƱ�㷨����ѡֵ��������֣�������ÿ��Ԫ�����ж���Ϊ0���Ǵ���0����0������Ϊ��ѡ������0���ж��Ƿ���֮ǰ�ĺ�ѡ��ȣ�����count
//д��1
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (const int& num : nums) {
            if (count == 0) {
                candidate = num;
                count++;
            }
            else {
                if (num == candidate) count++;
                else count--;
            }
        }
        return candidate;
    }
};
//д��2
class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
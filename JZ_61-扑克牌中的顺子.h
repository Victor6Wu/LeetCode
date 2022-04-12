//����׼ȷ��˵���˿���ûʲô��ϵ����������Ϊ5�����飬����[0,13]�����֣�����0���Ա�ʾ��������֣��ж������е����ܲ����ų�˳��
//��[0��0��1��2��5]���Կ���[1��2��3��4��5]
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//����1
class Solution1 {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, index = 0;
        while (nums[index] == 0) {
            count++;
            index++;
        }
        for (int i = index + 1; i <= 4; i++) {
            if (nums[i] - nums[i - 1] == 1) continue;
            else if (nums[i] - nums[i - 1] == 0) return false;
            else {
                if (nums[i] - nums[i - 1] - 1 <= count) {
                    count -= (nums[i] - nums[i - 1] - 1);
                }
                else return false;
            }
        }
        return true;
    }
};

//����2����ȡ�ؼ�������
//1.����0����û���ظ�Ԫ�أ�2.����0���⣬max - min < 5
//�����ظ���񣬿�����mapȷ����Ҳ���������ȷ������������ַ�����map+��������������+����
class Solution2 {
public:
    bool isStraight(vector<int>& nums) {
        unordered_map<int, int> table;
        int minNum = 14, maxNum = -1;
        for (int i = 0; i < 5; i++) {
            if (nums[i] != 0) {
                if (table[nums[i]] != 0) return false;
                table[nums[i]]++;
                minNum = min(minNum, nums[i]);
                maxNum = max(maxNum, nums[i]);
            }
        }
        if (maxNum - minNum < 5) return true;
        return false;
    }
};

class Solution3 {
public:
    bool isStraight(vector<int>& nums) {
        int minIndex = 0;       //��¼��һ������0��λ��
        sort(nums.begin(), nums.end());
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0) minIndex++;
            else if (nums[i] == nums[i + 1]) return false;
        }
        if (nums[4] - nums[minIndex] < 5) return true;
        return false;
    }
};
//����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//����Ĺؼ�������һ�����ʵ������㷨������������x,y����ô�ж�x��ǰ����y��ǰ�أ�
//��һֱ�۵��뷨�����û����򣬵���Щ��������������鷳������3,30��30Ӧ��С��3
//���Ա��������˼�룺ƴ���ַ���x+y>y+x����x�����ڡ�y

//д��1���ڿ��ŵĻ������޸�
class Solution1 {
public:
    void quicksort(vector<string>& nums, int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        string pivot = nums[left];
        while (i < j) {
            while (i < j && pivot + nums[j] <= nums[j] + pivot) j--;
            if (i < j) nums[i] = nums[j];    //С��Ų��ǰ��ȥ
            while (i < j && nums[i] + pivot <= pivot + nums[i]) i++;
            if (i < j) nums[j] = nums[i];     //���Ų������ȥ
        }
        nums[i] = pivot;
        quicksort(nums, left, i - 1);
        quicksort(nums, i + 1, right);
    }
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        for (const int& num : nums) {
            vec.push_back(to_string(num));
        }
        quicksort(vec, 0, vec.size() - 1);
        string ans;
        for (const string str : vec) {
            ans += str;
        }
        return ans;
    }
};

//�޸����ú���
class Solution2 {
public:
    static bool cmp(string& a, string& b) {
        return a + b < b + a;
    }
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        for (const int& num : nums) {
            vec.push_back(to_string(num));
        }
        sort(vec.begin(), vec.end(), cmp);
        string ans;
        for (const string& str : vec) {
            ans += str;
        }
        return ans;
    }
};
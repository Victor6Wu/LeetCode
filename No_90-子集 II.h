//����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯���ܰ����ظ����Ӽ������صĽ⼯�У��Ӽ����԰�����˳�����С�
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
        if (startIndex >= nums.size()) { // ��ֹ�������Բ��ӣ���Ϊ������������ѭ��
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i - 1] == nums[i]) {     //��Ϊ�Ѿ����������ˣ��ظ�Ԫ���ǽ�����
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
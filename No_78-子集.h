//����һ���������� nums �������е�Ԫ�ػ�����ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯���ܰ����ظ����Ӽ�������԰�����˳�򷵻ؽ⼯��
#include<vector>
using namespace std;

//����1���Ա���ݴ��룬ģ��No_39��ķ���1���ֳɿ��ǺͲ����Ǹõ����������
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp = {};
public:
    void backtracking(vector<int>& nums, int startIndex) {
        if (startIndex = nums.size()) {
            if (tmp.size() != 0) {                  //�ռ��������ǣ����ڵݹ��н���
                result.push_back(tmp);
            }
            return;
        }

        //�������õ�
        backtracking(nums, startIndex + 1);
        //�����õ�
        tmp.push_back(nums[startIndex]);
        backtracking(nums, startIndex + 1);
        tmp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        result.push_back({});
        return result;
    }
};

//����2������ģ�壬�ؼ�����ÿ�εݹ�ʱ��ִ��push������������ֹ������ſ���
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
        if (startIndex >= nums.size()) { // ��ֹ�������Բ��ӣ���Ϊ������������ѭ��
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
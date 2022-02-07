//����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�
//�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ�����������
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
 
//����1����No_90�Ĵ����Ͻ����޸ģ��޸Ľ���ռ��������޸�ȥ�ط�ʽ
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(vector<int>& nums, int startInddex, int endNum) {
        if (tmp.size() >= 2) {
            result.push_back(tmp);
        }
        if (startInddex >= nums.size()) {
            return;
        }
        //usetֻ���𱾲㣡
        unordered_set<int> uset;            //��setȥ�أ�Ҫע�ⲻ�������Ľ��ȥ�أ��������벻ͨ����Ҫ��ͬ��ȥ�أ���forѭ����ȥ��
        for (int i = startInddex; i < nums.size(); i++) {
            if (nums[i] < endNum || uset.find(nums[i]) != uset.end()) {        //ͬ���ظ���ȥ������ǰ��û���һ�����Ҳ������
                continue;
            }
            uset.insert(nums[i]);
            tmp.push_back(nums[i]);
            backtracking(nums, i + 1, nums[i]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        tmp.clear();
        backtracking(nums, 0, INT_MIN);
        return result;
    }
};

//�����Ż�����set�滻������
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(vector<int>& nums, int startInddex, int endNum) {
        if (tmp.size() >= 2) {
            result.push_back(tmp);
        }
        if (startInddex >= nums.size()) {
            return;
        }
        //usetֻ���𱾲㣡
        vector<bool> uset(201);            //������ȥ�أ�Ҫע�ⲻ�������Ľ��ȥ�أ��������벻ͨ����Ҫ��ͬ��ȥ�أ���forѭ����ȥ��
        for (int i = startInddex; i < nums.size(); i++) {
            if (nums[i] < endNum || uset[nums[i] + 100]) {        //ͬ���ظ���ȥ������ǰ��û���һ�����Ҳ������
                continue;
            }
            uset[nums[i] + 100] = true;
            tmp.push_back(nums[i]);
            backtracking(nums, i + 1, nums[i]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        tmp.clear();
        backtracking(nums, 0, INT_MIN);
        return result;
    }
};
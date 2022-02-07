//�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�
#include<vector>
#include<numeric>
using namespace std;

//����1����No_77�Ż�����������ֱ���޸ģ������ݱ�������Ż�
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void backtracking(int k, int startIndex, int n) {
        if (tmp.size() == k) {
            if (accumulate(tmp.begin(), tmp.end(), 0) == n) {
                result.push_back(tmp);
            }
            return;
        }

        for (int i = startIndex; i <= 10 - (k - tmp.size()); i++) {
            tmp.push_back(i);
            backtracking(k, i + 1, n);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, 1, n);
        return result;
    }
};

//����2���Ż�������һ�������ж�tmp��Ԫ�غ��Ƿ��Ѿ�����n
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void backtracking(int k, int startIndex, int n, int sum) {
        if (sum > n) {
            return;
        }

        if (tmp.size() == k) {
            if (sum == n) {
                result.push_back(tmp);
            }
            return;
        }

        for (int i = startIndex; i <= 10 - (k - tmp.size()); i++) {
            //����ڵ�
            tmp.push_back(i);
            sum += i;
            //�ݹ�
            backtracking(k, i + 1, n, sum);
            //�����ڵ�
            tmp.pop_back();
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        backtracking(k, 1, n, sum);
        return result;
    }
};
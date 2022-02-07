//������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ����԰�������˳�򷵻�
#include<vector>
using namespace std;

//���������ݷ�
class Solution1 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(int n, int k, int startIndex) {
        //��ֹ����
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            tmp.push_back(i);       //����ڵ�
            backtracking(n, k, i + 1); //�ݹ�
            tmp.pop_back();         //��������ڵ�
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

//���ݷ��Ż���ȥ����Щ�������ÿ��ǵģ��޸���forѭ������ֹ����
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void backtracking(int n, int k, int startIndex) {
        //��ֹ����
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (int i = startIndex; i <= n - (k - tmp.size()) + 1; i++) {
            tmp.push_back(i);       //����ڵ�
            backtracking(n, k, i + 1); //�ݹ�
            tmp.pop_back();         //��������ڵ�
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

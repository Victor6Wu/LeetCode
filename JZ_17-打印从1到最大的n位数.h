//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
#include<string>
#include<vector>    
using namespace std;

class Solution1 {
public:
    vector<int> printNumbers(int n) {
        string s;
        while (n-- > 0) {
            s.push_back('9');
        }
        vector<int> ans;
        for (int i = 1; i <= stoll(s); i++) {
            ans.push_back(i);
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> printNumbers(int n) {
        long long max = 1;
        while (n-- > 0) {
            max *= 10;
        }
        vector<int> ans;
        for (int i = 1; i < max; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};
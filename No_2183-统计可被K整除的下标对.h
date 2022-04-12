//����һ���±�� 0 ��ʼ������Ϊ n ���������� nums ��һ������ k ���������������������±�� (i, j) ����Ŀ��
//0 <= i < j <= n - 1 ��
//nums[i] * nums[j] �ܱ� k ������
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;

//������Ҫ�����ǣ����׳�ʱ���������int
class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                cnt[i] = 0;
                if (i * i != k) {
                    cnt[k / i] = 0;
                }
            }
        }

        long long ans = 0;
        for (int num : nums) {
            int need = k / gcd(num, k);
            ans += cnt[need];
            for (auto&& [fac, occ] : cnt) {
                if (num % fac == 0) {
                    ++occ;
                }
            }
        }

        return ans;
    }
};

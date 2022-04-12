//����һ���������� nums ��һ������ target ��
//�������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��
//���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ��
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

//˼·����������ת�������ܺ͵����⣬��������ѡһЩԪ��ʹ�ú͸պõ���Ŀ��ֵ��left�� = ��target + sum��/ 2
//����1�����ݷ����ᳬʱ
//����2����̬�滮��ע�Ȿ������֪��װ�������Ǿ��������������ķ�������ϣ��ж����֣�����dp[j]Ӧ�ñ�ʾ��������j�ı����ķ�����
//��ά����dp[i][j] = dp[i -1][j] +dp [i - 1][j - nums[i]]
//һά����dp[j] = dp[j] + dp[j - nums[i]]
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;        //���target����ֵ����sum���϶������ҳ����
        if ((target + sum) % 2 == 1) return 0;         //�����target + sum�����������϶������ҳ����
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;                              //���Ϊ0ֻ��һ�ַ���
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
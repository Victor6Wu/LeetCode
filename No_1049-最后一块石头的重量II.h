//��һ��ʯͷ������������ stones ��ʾ������ stones[i] ��ʾ�� i ��ʯͷ��������
//ÿһ�غϣ�����ѡ����������ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�
//��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
//��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y - x��
//������ֻ��ʣ��һ�� ʯͷ�����ش�ʯͷ ��С�Ŀ������� �����û��ʯͷʣ�£��ͷ��� 0��
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

//���No_416���˼�룬�������ת�ɣ�������ֳ������֣�ʹ�������ֵĲ�ֵ��С
//����֮�����ܺ͵�һ����Ϊ������������������Ԫ��ʹ�ñ�����������
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
		int n = stones.size();
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int target = sum / 2;	//�ܺ͵�ƽ��ֵ��Ϊ��������������ȡ��
		vector<int> dp(target + 1, 0);
		//dp[j]��ʾ����������˵������������ʵ����������Ϊj�ı����������Ա�dp[j]��ô�ص�ʯͷ��
		for (int i = 0; i < n; i++) {
			for (int j = target; j >= stones[i]; j--) {		//�Ӵ�С������������ֹ��������������ʱ����Ϊ���������Ĳ����൱��ά��ԭ��dp[j]
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);			//�뷽��1Ψһ��ͬ�ľ���dp�ĺ��壬Ҳ���������ڴ˴�
			}
		}

		return (sum - dp[target]) - dp[target];
    }
};
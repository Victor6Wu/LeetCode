//��No_122�Ļ����������˽��������ѣ���Ҫ���ǽ��׵�ʱ�䣬�����ܲ�ֳ�ÿһ�콻��
#include<vector>
using namespace std;

//˼·����̰�ģ������ѿ����������Ʊ�ĳɱ�֮һ��ֻҪ�ҵ�������ͼ���Ƿ�Ϳ��Խ��н���
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = prices[0] + fee;              //���ｫ�����ѷ�������۸���п���
        int profit = 0;     
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {        //�������͵ļ۸�
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) {         //����������ͼʱ
                profit += prices[i] - buy;

                //��һ���ǳ��ؼ���������һ֧��Ʊʱ���ͻ��������ͬ�۸����������������һֻ��Ʊ��Ȩ��
                //��������Ŀ����Ӧ�Ժ����Ʊ�۸��������ӵ�������Ͼ���̰�ĵĽǶ���˵���������ֻ�ý���һ�Σ�����һ��������
                buy = prices[i];                
            }
        }
        return profit;
    }
};

//��̬�滮������No_122�Ļ����ϣ�������ʱ������һ�������ѿ�֧����
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0)); //0��ʾ���й�Ʊ��1��ʾ������
        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // ע�������Ǻ�121. ������Ʊ�����ʱ��Ψһ��ͬ�ĵط���
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[len - 1][1];
    }
};
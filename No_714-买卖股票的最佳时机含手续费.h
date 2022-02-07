//��No_122�Ļ����������˽��������ѣ���Ҫ���ǽ��׵�ʱ�䣬�����ܲ�ֳ�ÿһ�콻��
#include<vector>
using namespace std;

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
                buy = prices[i];
            }
        }
        return profit;
    }
};
//n ������վ��һ�š�����һ���������� ratings ��ʾÿ�����ӵ����֡�����Ҫ��������Ҫ�󣬸���Щ���ӷַ��ǹ���
//ÿ���������ٷ��䵽 1 ���ǹ���
//���������������ָ��ߵĺ��ӻ��ø�����ǹ���
//�����ÿ�����ӷַ��ǹ������㲢������Ҫ׼���� �����ǹ���Ŀ ��
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max((candyVec[i + 1] + 1), candyVec[i]);
            }
        }
        int sum = 0;
        for (int it : candyVec) {
            sum += it;
        }
        return sum;
    }
};
//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
#include<vector>
using namespace std;

//ģ�ⷨ���ر�ע�⣺
//1.�����еı仯��Χ���߽�Ľ���ֻ��Ҫ��ӡһ�μ��ɣ������ظ������
//2.����������Ϊ���������м����ֵ��л��е�ʱ��һ��Ҫ����ػ����߻�ͷ·��
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        vector<int> ans;
        int m = matrix[0].size();
        int x = 0, y = 0;
        //�������л������
        while (x <= (n - 1) / 2 && y <= (m - 1) / 2) {
            //����
            for (int j = y; j < m - y; j++) {
                ans.emplace_back(matrix[x][j]);
            }
            //����
            for (int i = x + 1; i < n - x; i++) {
                ans.emplace_back(matrix[i][m - y - 1]);
            }
            //����
            for (int j = m - y - 2; j >= y && n - x - 1 != x; j--) {    //����һ��Ҫ����һ�����������������������������ͬ��
                ans.emplace_back(matrix[n - x - 1][j]);
            }
            //����
            for (int i = n - x - 2; i > x && m - y - 1 != y; i--) {     //����һ��Ҫ����һ�������������������������µ���ͬ��
                ans.emplace_back(matrix[i][y]);
            }
            x++;
            y++;
        }
        return ans;
    }
};
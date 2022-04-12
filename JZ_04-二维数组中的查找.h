//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������
#include<vector>
using namespace std;

//����ɨ�裬�����Ͻǿ�ʼ�������������������ų��Ҳ�ɨ������У��Լ�ͬһ�����ĵ�
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            //��������
            while (i < row && j >= 0) {
                if (matrix[i][j] == target) return true;
                else if (matrix[i][j] > target) j--;            //��Ŀ����ˣ��о�����Ų
                else break;
            }

            //��������
            while (i < row && j >= 0) {
                if (matrix[i][j] == target) return true;
                else if (matrix[i][j] < target) i++;            //��Ŀ��С�ˣ�������Ų
                else break;
            }
        }

        return false;   
    }
};
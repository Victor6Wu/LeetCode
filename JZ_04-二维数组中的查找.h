//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include<vector>
using namespace std;

//线性扫描，从右上角开始，往左往下搜索，逐步排除右侧扫描过的列，以及同一行左侧的点
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            //从右往左
            while (i < row && j >= 0) {
                if (matrix[i][j] == target) return true;
                else if (matrix[i][j] > target) j--;            //比目标大了，列就往左挪
                else break;
            }

            //从上往下
            while (i < row && j >= 0) {
                if (matrix[i][j] == target) return true;
                else if (matrix[i][j] < target) i++;            //比目标小了，行往下挪
                else break;
            }
        }

        return false;   
    }
};
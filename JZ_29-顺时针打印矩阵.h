//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
#include<vector>
using namespace std;

//模拟法，特别注意：
//1.行与列的变化范围，边界的交点只需要打印一次即可，避免重复输出；
//2.行数或列数为奇数，即中间会出现单行或单列的时候，一定要避免回环（走回头路）
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        vector<int> ans;
        int m = matrix[0].size();
        int x = 0, y = 0;
        //遍历所有环的起点
        while (x <= (n - 1) / 2 && y <= (m - 1) / 2) {
            //往右
            for (int j = y; j < m - y; j++) {
                ans.emplace_back(matrix[x][j]);
            }
            //往下
            for (int i = x + 1; i < n - x; i++) {
                ans.emplace_back(matrix[i][m - y - 1]);
            }
            //往左
            for (int j = m - y - 2; j >= y && n - x - 1 != x; j--) {    //这里一定要给行一个限制条件，避免向右与向左的是同行
                ans.emplace_back(matrix[n - x - 1][j]);
            }
            //往上
            for (int i = n - x - 2; i > x && m - y - 1 != y; i--) {     //这里一定要给列一个限制条件，避免向上与向下的是同列
                ans.emplace_back(matrix[i][y]);
            }
            x++;
            y++;
        }
        return ans;
    }
};
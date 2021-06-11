#pragma once
//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    //solution 1: 暴力解法，时间复杂度O(m^2 n)=O(mn)+O(mn)·O(n)，空间复杂度：O(mn)
    int maximalRectangle1(vector<vector<char>>& matrix) {
        int m = matrix.size();                              //矩阵行数
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();                           //矩阵列数
        //构造一个m*n的二维数组，存放每个位置体现的所在行的“1”连续情况
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }
        //循环left，每个位置作为矩阵的右下角，计算坐上所以可能的矩阵的面积
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {                  //只关注矩阵中为1的位置
                    continue;
                }
                int width = left[i][j];
                int area = width;
                //在该位置往上查找
                for (int k = i - 1; k >= 0; k--) {
                    width = min(width, left[k][j]);
                    area = max(area, (i - k + 1) * width);      //更新以i，j位置为右下角的矩阵中面积的最大值
                }
                ret = max(ret, area);                       //更新所有位置中的最大值
            }   
        }
        return ret;
    }

    //solution 2: 单调栈法（动态规划法），借鉴No_84柱状图中的最大矩阵面积的solution3，以列为单位进行计算
        int maximalRectangle2(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if (m == 0) {
                return 0;
            }
            int n = matrix[0].size();
            //构造一个m*n的二维数组，存放每个位置体现的所在行的“1”连续情况，该矩阵的每列就体现为一个个柱状图！
            vector<vector<int>> left(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == '1') {
                        left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                    }
                }
            }

            int ret = 0;
            for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
                vector<int> up(m, 0), down(m, 0);           //存储每个位置的上下（No_84中的左右）边界

                stack<int> stk;
                for (int i = 0; i < m; i++) {
                    while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                        stk.pop();
                    }
                    up[i] = stk.empty() ? -1 : stk.top();
                    stk.push(i);
                }
                stk = stack<int>();
                for (int i = m - 1; i >= 0; i--) {
                    while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                        stk.pop();
                    }
                    down[i] = stk.empty() ? m : stk.top();
                    stk.push(i);
                }
                //根据记录好的边界数组，统一计算矩形面积
                for (int i = 0; i < m; i++) {
                    int height = down[i] - up[i] - 1;
                    int area = height * left[i][j];
                    ret = max(ret, area);
                }
            }
            return ret;
        }
};

//给定一个三角形 triangle ，找出自顶向下的最小路径和。
#include<vector>
#include<algorithm>
using namespace std;


//动态规划，从上往下考虑
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
                else triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
        return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    }
};

//从下往上的思路
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
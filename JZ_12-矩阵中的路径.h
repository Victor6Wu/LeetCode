//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
#include<vector>
#include<string>
using namespace std;

//深度优先搜索
class Solution1 {
private:
    int n, m;   //n行，m列
public:
    //record用于记录对应网格的字符是否已经被占用；row、col代表当前搜索到的行\列位置
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& record, int row, int col, string& word, int index) {
        //如果超出网格范围或者已经被占用，则该路不通
        if ((row < 0 || row >= n) || (col < 0 || col >= m) || record[row][col]) return false;
        //如果没超出范围，也未被占用，但是与当前判断字符不符，也说明此路不通
        else if (board[row][col] != word[index]) return false;
        //网格的当前字符是满足条件的
        else {
            //判断是否已经处理到word的最后一个字符
            if (index == word.size() - 1) return true;

            //如果不是就还需要继续向四周探索
            record[row][col] = true;
            if (dfs(board, record, row - 1, col, word, index + 1) || dfs(board, record, row + 1, col, word, index + 1) || dfs(board, record, row, col - 1, word, index + 1) || dfs(board, record, row, col + 1, word, index + 1))
                return true;

            //如果分支都没有走通的，要回退当前网格
            record[row][col] = false;
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> record(n, vector<bool>(m, false));      //记录字符是否被占用
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, record, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};

//代码优化，不需要额外的数组表示网格中的字符是否被占用，
class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0';     //当前网格被占用就将其置为空
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};
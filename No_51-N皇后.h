//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    bool isValid(int row, int col, vector<string>& chessBoard, int n) {
        //因为是一层一层填充，无需检验行的有效性，只用关注已经填充过的，也就是棋盘的上半部分
        //检测列
        for (int i = 0; i < row; i++) {
            if (chessBoard[i][col] == 'Q')
                return false;
        }
        //检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        //检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row, vector<string>& chessBoard) {
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessBoard, n)) {         //判断当前位置填入棋子是否合法，主要是会不会与已经填入的冲突
                chessBoard[row][col] = 'Q';
                backtracking(n, row + 1, chessBoard);
                chessBoard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n, string(n, '.'));       //提前创建好空棋盘
        backtracking(n, 0, chessBoard);
        return result;
    }
};
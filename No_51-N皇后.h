//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//棋子会攻击与其同行、列、左右倾斜45°的直线上的棋子
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
        //对于当前行，0至n-1的位置都可以考虑摆放棋子
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

//基于位运算回溯
//用三个整数columns、diagonals1、diagonal2分别代表之前的棋子位置对于当前行的影响：对同列的、对45°斜线、对135°斜线
//必须要有个方法记录之前棋子的摆放位置，保证最后能返回结果
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();//记录最终的结果
        auto queens = vector<int>(n, -1);       //记录棋子的摆放位置，以用于后面生成棋牌（结果），queens[i]表示第i行的哪个位置为Q
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>>& solutions, vector<int>& queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        }
        else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            //遍历本行所有的可选位置
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);      //本行选取的位置，从最低位的1开始
                availablePositions = availablePositions & (availablePositions - 1); //将最低位1置为0
                int column = __builtin_ctz(position);       //x末尾0的个数，即选取的位置
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int>& queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
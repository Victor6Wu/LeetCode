//n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
//���ӻṥ������ͬ�С��С�������б45���ֱ���ϵ�����
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    bool isValid(int row, int col, vector<string>& chessBoard, int n) {
        //��Ϊ��һ��һ����䣬��������е���Ч�ԣ�ֻ�ù�ע�Ѿ������ģ�Ҳ�������̵��ϰ벿��
        //�����
        for (int i = 0; i < row; i++) {
            if (chessBoard[i][col] == 'Q')
                return false;
        }
        //������Ϸ�
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        //������Ϸ�
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
        //���ڵ�ǰ�У�0��n-1��λ�ö����Կ��ǰڷ�����
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessBoard, n)) {         //�жϵ�ǰλ�����������Ƿ�Ϸ�����Ҫ�ǻ᲻�����Ѿ�����ĳ�ͻ
                chessBoard[row][col] = 'Q';
                backtracking(n, row + 1, chessBoard);
                chessBoard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n, string(n, '.'));       //��ǰ�����ÿ�����
        backtracking(n, 0, chessBoard);
        return result;
    }
};

//����λ�������
//����������columns��diagonals1��diagonal2�ֱ����֮ǰ������λ�ö��ڵ�ǰ�е�Ӱ�죺��ͬ�еġ���45��б�ߡ���135��б��
//����Ҫ�и�������¼֮ǰ���ӵİڷ�λ�ã���֤����ܷ��ؽ��
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();//��¼���յĽ��
        auto queens = vector<int>(n, -1);       //��¼���ӵİڷ�λ�ã������ں����������ƣ��������queens[i]��ʾ��i�е��ĸ�λ��ΪQ
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
            //�����������еĿ�ѡλ��
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);      //����ѡȡ��λ�ã������λ��1��ʼ
                availablePositions = availablePositions & (availablePositions - 1); //�����λ1��Ϊ0
                int column = __builtin_ctz(position);       //xĩβ0�ĸ�������ѡȡ��λ��
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
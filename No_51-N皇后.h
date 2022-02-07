//n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
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
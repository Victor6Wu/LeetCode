//����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��
//���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
#include<vector>
#include<string>
using namespace std;

//�����������
class Solution1 {
private:
    int n, m;   //n�У�m��
public:
    //record���ڼ�¼��Ӧ������ַ��Ƿ��Ѿ���ռ�ã�row��col����ǰ����������\��λ��
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& record, int row, int col, string& word, int index) {
        //�����������Χ�����Ѿ���ռ�ã����·��ͨ
        if ((row < 0 || row >= n) || (col < 0 || col >= m) || record[row][col]) return false;
        //���û������Χ��Ҳδ��ռ�ã������뵱ǰ�ж��ַ�������Ҳ˵����·��ͨ
        else if (board[row][col] != word[index]) return false;
        //����ĵ�ǰ�ַ�������������
        else {
            //�ж��Ƿ��Ѿ�����word�����һ���ַ�
            if (index == word.size() - 1) return true;

            //������Ǿͻ���Ҫ����������̽��
            record[row][col] = true;
            if (dfs(board, record, row - 1, col, word, index + 1) || dfs(board, record, row + 1, col, word, index + 1) || dfs(board, record, row, col - 1, word, index + 1) || dfs(board, record, row, col + 1, word, index + 1))
                return true;

            //�����֧��û����ͨ�ģ�Ҫ���˵�ǰ����
            record[row][col] = false;
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> record(n, vector<bool>(m, false));      //��¼�ַ��Ƿ�ռ��
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, record, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};

//�����Ż�������Ҫ����������ʾ�����е��ַ��Ƿ�ռ�ã�
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
        board[i][j] = '\0';     //��ǰ����ռ�þͽ�����Ϊ��
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};
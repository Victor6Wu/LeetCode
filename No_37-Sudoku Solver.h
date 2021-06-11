//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules :
//Each of the digits 1 - 9 must occur exactly once in each row.
//Each of the digits 1 - 9 must occur exactly once in each column.
//Each of the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.
//The '.' character indicates empty cells.
#include<vector>
using namespace std;

class Solution {
	//solution 1: 递归，利用No_36第二种方法，一次循环将对应数字在三个数组中的位置变为true，再循环利用递归，尝试往空白位置添加数字，但是要满足三个数组中对应位置为flase
	//之后递归下去，填下一个空，当无法满足时要回溯，尝试另一个数字填入
private:
	bool line[9][9];
	bool column[9][9];
	bool block[3][3][9];
	bool valid;
	vector<pair<int, int>> spaces;

public:
	void dfs(vector<vector<char>>& board, int pos) {
		if (pos == spaces.size()) {
			valid = true;
			return;
		}

		auto i = spaces[pos].first;	//取出空白位的索引
		auto j = spaces[pos].second;	//取出空白位的索引
		for (int digit = 0; digit < 9 && !valid; ++digit) {
			if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
				board[i][j] = digit + '1';
				dfs(board, pos + 1);
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
			}
		}

	}
	void solveSudoku(vector<vector<char>>& board) {
		memset(line, false, sizeof(line));
		memset(column, false, sizeof(column));
		memset(block, false, sizeof(block));
		valid = false;
		
		for (int i = 0; i < 9; ++i) {
			for (int j = 0;j<9;++j){
				if (board[i][j] == '.') {
					spaces.emplace_back(i, j);
				}
				else {
					int digit = board[i][j] - '1';
					line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
				}
			}
		}
		dfs(board, 0);
	}

	//solution 2: 对solution 1 中用于储存数字出现情况的数据进行优化 位运算进行优化
private:
	int line[9];
	int column[9];
	int block[3][3];
	bool valid;
	vector<pair<int, int>> spaces;

public:
	//用于修改对应位置
	void flip(int i, int j, int digit) {
		line[i] ^= (1 << digit);
		column[j] ^= (1 << digit);
		block[i / 3][j / 3] ^= (1 << digit);
	}

	void dfs(vector<vector<char>>& board, int pos) {
		if (pos == spaces.size()) {
			valid = true;
			return;
		}

		auto i = spaces[pos].first;	//取出空白位的索引
		auto j = spaces[pos].second;	//取出空白位的索引
		int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
		for (; mask && !valid; mask &= (mask - 1)) {
			int digitMask = mask & (-mask);
			int digit = __builtin_ctz(digitMask);
			flip(i, j, digit);
			board[i][j] = digit + '0' + 1;
			dfs(board, pos + 1);
			flip(i, j, digit);
		}
	}

	void solveSudoku(vector<vector<char>>& board) {
		memset(line, 0, sizeof(line));
		memset(column, 0, sizeof(column));
		memset(block, 0, sizeof(block));
		valid = false;

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					spaces.emplace_back(i, j);
				}
				else {
					int digit = board[i][j] - '0' - 1;
					flip(i, j, digit);
				}
			}
		}

		dfs(board, 0);
	}

	//solution 3: 递归的优化方法，枚举+递归回溯，solution2的优化
	//先解决那些空格可唯一确定的，再对剩余无法唯一确定的空格进行递归+回溯
	void solveSudoku(vector<vector<char>>& board) {
		memset(line, 0, sizeof(line));
		memset(column, 0, sizeof(column));
		memset(block, 0, sizeof(block));
		valid = false;

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int digit = board[i][j] - '0' - 1;
					flip(i, j, digit);
				}
			}
		}

		while (true) {
			int modified = false;
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					if (board[i][j] == '.') {
						int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
						if (!(mask & (mask - 1))) {
							int digit = __builtin_ctz(mask);
							flip(i, j, digit);
							board[i][j] = digit + '0' + 1;
							modified = true;
						}
					}
				}
			}
			if (!modified) {
				break;
			}
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					spaces.emplace_back(i, j);
				}
			}
		}

		dfs(board, 0);
	}
};
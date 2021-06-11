#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//solut 1:自写代码，三次循环，行、列、子块
	bool isValidSudoku1(vector<vector<char>>& board) {
		unordered_map<char, int> table;
		//特别注意如何初始化这个哈希表，int怎么转成char
		//初始化哈希表，每个键值表示出现的次数，初始时都为1，检测到一次就-1；
		for (int i = 1; i < 10; i++) {
			table[(char)(i + 48)] = 1;
			//table[i + '0'] = 1;
		}

		const unordered_map<char, int> temp = table;
		//行
		for (int i = 0; i < 9; ++i) {
			unordered_map<char, int> table = temp;
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					if (table[board[i][j]] == 1)		//判断是不是还为1
					{
						--table[board[i][j]];
					}
					else {
						return false;
					}
				}
			}
		}

		//列
		for (int i = 0; i < 9; ++i) {
			unordered_map<char, int> table = temp;
			for (int j = 0; j < 9; ++j) {
				if (board[j][i] != '.') {
					if (table[board[j][i]] == 1)
					{
						--table[board[j][i]];
					}
					else
					{
						return false;
					}
				}
			}
		}

		//子块
		for (int i = 0; i < 9; i+=3) {
			for (int j = 0; j < 9; j+=3) {
				unordered_map<char, int> table = temp;
				for(int m = i; m < i + 3; ++m) {
					for (int n = j; n < j + 3; ++n) {
						if (board[m][n] != '.') {
							if (table[board[m][n]] == 1)
							{
								--table[board[m][n]];
							}
							else
							{
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}

	//solution 2: 优化代码，将 行、列、格 一起遍历；
	//关键在于，9*9的矩阵太小了，用数组直接表示即可，空间复杂度很小；
	bool isValidSudoku2(vector<vector<char>>& board) {
		//数组中的每个位置对应一个数字出现的次数，表示一个子行/子列/子格下，某个数字出现的次数
		bool hang[9][9] = { 0 };
		bool lie[9][9] = { 0 };
		bool ge[9][9] = { 0 };
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				//cout<<board[i][j]<<' ';
				if (board[i][j] - '1' >= 0 && board[i][j] - '1' <= 9) {
					int id = board[i][j] - '1';		//计算当前字符对应数组中的索引
					//判断条件：
					if (hang[i][id] == true)		//以行为单位存放矩阵每行数字出现的次数
						return false;
					if (lie[id][j] == true)			//以列为单位存放矩阵每列数字出现的次数
						return false;

					//用i、j判断当前点属于第几个子格：行索引决定大致范围，列索引决定具体位置
					if (ge[(i / 3) * 3 + j / 3][id] == true) //以行为单位存放矩阵每子格中数字出现的次数
						return false;

					hang[i][id] = true;
					lie[id][j] = true;
					ge[(i / 3) * 3 + j / 3][id] = true;
				}
			}
		}
		return true;
	}
};
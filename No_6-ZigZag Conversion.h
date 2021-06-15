//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility)
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1：利用二维数组
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string ans;
		int n = s.length();
		int numUnit = n % (2 * numRows - 2) == 0 ? n / (2 * numRows - 2) : n / (2 * numRows - 2) + 1;			//以N的左列+对角线为一个单元
		int numColumns = numUnit * (numRows - 1);			//确定列数
		vector<vector<char>> cell(numRows, vector<char> (numColumns, ' '));
		int row_ptr = 0;		//行指针
		int col_ptr = 0;		//列指针
		bool signal = true;
		for (int i = 0; i < n; ++i) {
			cell[row_ptr][col_ptr] = s[i];
			if (row_ptr == 0) signal = true;	//信号量为true，表示列数固定，行增加
			//注意此处是numRows-1，不是numRows
			else if (row_ptr == numRows - 1) signal = false;	//信号量为false，表示填充对角线元素，行数和列数同时变化

			//根据信号量确定行数和列数的变化方式
			if (signal == true) {
				row_ptr++;
			}
			else {
				row_ptr--;		//行数-1
				col_ptr++;		//列数+1
			}
		}

		//输出结果
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < numColumns; ++j) {
				if (cell[i][j] != ' ') {
					ans.push_back(cell[i][j]);
				}
			}
		}
		return ans;
	}

	//solution 2：按行排序，与solution1相似，只是采用一维数组
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		
		vector<string> rows(min(numRows, int(s.size())));		//为了防止给的字符串很短
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;		//采用string存储字符的好处在于直接+即可，不需要给定是第几列，当然solution1中的行vector如果不在初始化的时候确定大小，也可以push_back
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;		//在第一行和最后一行操作完毕后要取反方向
			curRow += goingDown ? 1 : -1;
		}

		string ans;
		for (string row : rows) ans += row;
		return ans;
	}

	//solution 3:按行访问，按照与逐行读取Z字形图案相同的顺序访问字符串
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		string ans;
		int n = s.size();
		int cycleLen = 2 * numRows - 2;

		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j + i < n; j+=cycleLen) {
				ans += s[j + i];
				//考虑是否为中间行
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
					ans += s[j + cycleLen - i];
				}
			}
		}
		return ans;
	}
};

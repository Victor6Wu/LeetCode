//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility)
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1�����ö�ά����
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string ans;
		int n = s.length();
		int numUnit = n % (2 * numRows - 2) == 0 ? n / (2 * numRows - 2) : n / (2 * numRows - 2) + 1;			//��N������+�Խ���Ϊһ����Ԫ
		int numColumns = numUnit * (numRows - 1);			//ȷ������
		vector<vector<char>> cell(numRows, vector<char> (numColumns, ' '));
		int row_ptr = 0;		//��ָ��
		int col_ptr = 0;		//��ָ��
		bool signal = true;
		for (int i = 0; i < n; ++i) {
			cell[row_ptr][col_ptr] = s[i];
			if (row_ptr == 0) signal = true;	//�ź���Ϊtrue����ʾ�����̶���������
			//ע��˴���numRows-1������numRows
			else if (row_ptr == numRows - 1) signal = false;	//�ź���Ϊfalse����ʾ���Խ���Ԫ�أ�����������ͬʱ�仯

			//�����ź���ȷ�������������ı仯��ʽ
			if (signal == true) {
				row_ptr++;
			}
			else {
				row_ptr--;		//����-1
				col_ptr++;		//����+1
			}
		}

		//������
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < numColumns; ++j) {
				if (cell[i][j] != ' ') {
					ans.push_back(cell[i][j]);
				}
			}
		}
		return ans;
	}

	//solution 2������������solution1���ƣ�ֻ�ǲ���һά����
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		
		vector<string> rows(min(numRows, int(s.size())));		//Ϊ�˷�ֹ�����ַ����ܶ�
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;		//����string�洢�ַ��ĺô�����ֱ��+���ɣ�����Ҫ�����ǵڼ��У���Ȼsolution1�е���vector������ڳ�ʼ����ʱ��ȷ����С��Ҳ����push_back
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;		//�ڵ�һ�к����һ�в�����Ϻ�Ҫȡ������
			curRow += goingDown ? 1 : -1;
		}

		string ans;
		for (string row : rows) ans += row;
		return ans;
	}

	//solution 3:���з��ʣ����������ж�ȡZ����ͼ����ͬ��˳������ַ���
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		string ans;
		int n = s.size();
		int cycleLen = 2 * numRows - 2;

		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j + i < n; j+=cycleLen) {
				ans += s[j + i];
				//�����Ƿ�Ϊ�м���
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
					ans += s[j + cycleLen - i];
				}
			}
		}
		return ans;
	}
};

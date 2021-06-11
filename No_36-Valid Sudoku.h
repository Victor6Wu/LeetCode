#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//solut 1:��д���룬����ѭ�����С��С��ӿ�
	bool isValidSudoku1(vector<vector<char>>& board) {
		unordered_map<char, int> table;
		//�ر�ע����γ�ʼ�������ϣ��int��ôת��char
		//��ʼ����ϣ��ÿ����ֵ��ʾ���ֵĴ�������ʼʱ��Ϊ1����⵽һ�ξ�-1��
		for (int i = 1; i < 10; i++) {
			table[(char)(i + 48)] = 1;
			//table[i + '0'] = 1;
		}

		const unordered_map<char, int> temp = table;
		//��
		for (int i = 0; i < 9; ++i) {
			unordered_map<char, int> table = temp;
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					if (table[board[i][j]] == 1)		//�ж��ǲ��ǻ�Ϊ1
					{
						--table[board[i][j]];
					}
					else {
						return false;
					}
				}
			}
		}

		//��
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

		//�ӿ�
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

	//solution 2: �Ż����룬�� �С��С��� һ�������
	//�ؼ����ڣ�9*9�ľ���̫С�ˣ�������ֱ�ӱ�ʾ���ɣ��ռ临�ӶȺ�С��
	bool isValidSudoku2(vector<vector<char>>& board) {
		//�����е�ÿ��λ�ö�Ӧһ�����ֳ��ֵĴ�������ʾһ������/����/�Ӹ��£�ĳ�����ֳ��ֵĴ���
		bool hang[9][9] = { 0 };
		bool lie[9][9] = { 0 };
		bool ge[9][9] = { 0 };
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				//cout<<board[i][j]<<' ';
				if (board[i][j] - '1' >= 0 && board[i][j] - '1' <= 9) {
					int id = board[i][j] - '1';		//���㵱ǰ�ַ���Ӧ�����е�����
					//�ж�������
					if (hang[i][id] == true)		//����Ϊ��λ��ž���ÿ�����ֳ��ֵĴ���
						return false;
					if (lie[id][j] == true)			//����Ϊ��λ��ž���ÿ�����ֳ��ֵĴ���
						return false;

					//��i��j�жϵ�ǰ�����ڵڼ����Ӹ��������������·�Χ����������������λ��
					if (ge[(i / 3) * 3 + j / 3][id] == true) //����Ϊ��λ��ž���ÿ�Ӹ������ֳ��ֵĴ���
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
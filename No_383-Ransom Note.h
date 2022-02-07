//���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�
//������ԣ����� true �����򷵻� false ��
//magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
#include<string>
#include<vector>
using namespace std;

//�޸�No_242�⣬���ж������ĳ�<0
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.size() > magazine.size()) {
			return false;
		}

		int record[58] = { 0 };
		for (const char& it : magazine) {
			record[it - 'A']++;
		}

		for (const char& it : ransomNote) {
			record[it - 'A']--;
		}

		for (auto& it : record) {
			if (it < 0) return false;
		}
		return true;
	}
};
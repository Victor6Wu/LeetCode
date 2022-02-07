//���� s �� t �����ַ����������Ƿֱ����뵽�հ׵��ı��༭���������ж϶����Ƿ���ȡ�# �����˸��ַ���
//�����ȣ����� true �����򣬷��� false ��
//ע�⣺����Կ��ı������˸��ַ����ı�����Ϊ�ա�
#include<string>
using namespace std;

//solution1:�ع��ַ����������������ַ������ֱ�����ع�Ȼ���ٱȽ�
class Solution1 {
public:
	bool backspaceCompare(string s, string t) {
		string comS, comT;
		for (char it : s) {
			if (it != '#') {
				comS.push_back(it);
				continue;
			}
			if (it == '#' && comS.empty()) {
				continue;
			}
			comS.pop_back();
		}

		for (char it : t) {
			if (it != '#') {
				comT.push_back(it);
				continue;
			}
			if (it == '#' && comT.empty()) {
				continue;
			}
			comT.pop_back();
		}

		return (comS == comT);
	}
};

//solution2:˫ָ�뷨����������ַ���
class Solution2 {
public:
	bool backspaceCompare(string s, string t) {
		int i = s.size() - 1;
		int j = t.size() - 1;
		int skipS = 0, skipT = 0;
		while (i >= 0 || j >= 0) {			//��������ǻ�Ĺ�ϵ����Ϊ�����ַ����п��ܲ���ͬʱ��������
			while (j >= 0 && (skipT != 0 || t[j] == '#')) {
				if (t[j] == '#') {
					skipT++;
					j--;
				}
				else {
					skipT--;
					j--;
				}
			}
			while (i >= 0 && (skipS != 0 || s[i] == '#')) {
				if (s[i] == '#') {
					skipS++;
					i--;
				}
				else {
					skipS--;
					i--;
				}
			}

			if (i >= 0 && j >= 0) {
				if (s[i] != t[j]) {
					return false;
				}
				i--;
				j--;
				continue;		//�˴�����Ҫ��continue������һ���ַ���������ϣ���һ����û���������
			}

			if (i != j) return false;		//��������i��j���бȽϣ�����i=-1,j>=0ʱ�����ܻ�����ѭ��
		}
		return true;
	}
};
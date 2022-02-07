//���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
//��λ�� ָ����ͬ��ĸ�������γɵ��ַ�����������ͬ���ַ�������
#include<string>
#include<vector>
using namespace std;

//����1������λ���ж�
class Solution1 {
public:
	//�ж������ַ����Ƿ���λ��
	bool isAnagram(string s, string t) {
		int record[58] = { 0 };
		for (const char& it : s) {
			record[it - 'A']++;
		}

		for (const char& it : t) {
			record[it - 'A']--;
		}

		for (auto& it : record) {
			if (it != 0) return false;
		}
		return true;
	}
    vector<int> findAnagrams(string s, string p) {
        if (size(s) == 0 || size(p) == 0 || size(s) < size(p)) {
            return {};
        }
        vector<int> ans;
		int n = size(p);
		for (int i = 0; i <= size(s) - size(p); i++) {
			string tmp = s.substr(i, n);
			if (isAnagram(tmp, p)) {
				ans.push_back(i);
			}
		}
		return ans;
    }
};

//����2���������ķ������бȶԣ�����������ֱ�ӵ��ַ�����Ҫ�ظ������ϣ��
class Solution2 {
public:
	vector<int> findAnagrams(string s, string p) {
		int sLen = s.size();
		int pLen = p.size();
		if (sLen < pLen) return {};

		vector<int> ans;
		vector<int> sCount(26);
		vector<int> pCount(26);
		//��ʼ��s�ĵ�һ�����Լ�P��Ӧ�Ĺ�ϣ��
		for (int i = 0; i < pLen; i++) {
			pCount[p[i] - 'a']++;			//��¼�������е��ַ���
			sCount[s[i] - 'a']++;			//��¼�ַ������ַ����ִ���
		}
		//�жϵ�һ��λ��
		if (pCount == sCount) ans.push_back(0);

		//��������ʼ����ƶ��������е�һ���ַ���Ӧ����ֵ-1����β�����������ַ�+1
		for (int i = 0; i < sLen - pLen; i++) {
			sCount[s[i] - 'a']--;
			sCount[s[i + pLen] - 'a']++;

			if (pCount == sCount) ans.push_back(i + 1);
		}
		return ans;
	}
};

//����3���Ż��Ļ�����������һ������ֵ����ȥ�Ƚ�vector�Ĳ���
class Solution3 {
public:
	vector<int> findAnagrams(string s, string p) {
		int sLen = s.size();
		int pLen = p.size();
		if (sLen < pLen) return {};

		vector<int> ans;
		vector<int> count(26);				//��¼26����ĸ�ĳ��ִ����Ĳ�ֵ
		for (int i = 0; i < pLen; i++) {
			count[s[i] - 'a']++;			//�������е��ַ����ֵĴ���������
			count[p[i] - 'a']--;			//p���ַ����ּ����������е�-1
		}

		int differ = 0;		//����ֵ�����ڱ�ʾ���ִ�������Ӧ���ַ�����
		for (int i = 0; i < 26; i++) {
			if (count[i] != 0) {
				differ++;
			}
		}
		if (differ == 0) {
			ans.push_back(0);		//���µ�һ��������
		}
			
		//�ƶ�������������count�е������differ����ά����Ȼ��ֱ�Ӹ��ݸ��º��differ�����жϵ�ǰ�Ļ������Ƿ�����ĸ��λ��
		for (int i = 0; i < sLen - pLen; i++) {
			//�жϴ����ַ����ִ�����ֵ���ر�ע�⣺����ַ��Ӵ���ȥ�������һ����ĸ���ִ�����������ͬ���͡���ͬ�������������ת��ʱ�����б�Ҫ����differ
			if (count[s[i] - 'a'] == 1) {		//��ĸ�����Ӳ�ͬת����ͬ
				differ--;
			}
			else if (count[s[i] - 'a'] == 0) {	//��ĸ��������ͬת�ɲ�ͬ
				differ++;
			}
			count[s[i] - 'a']--;				//��ĸ����-1

			if (count[s[i + pLen] - 'a'] == -1) {		//��ĸ�����Ӳ�ͬת����ͬ
				differ--;
			}
			else if (count[s[i + pLen] - 'a'] == 0) {	//��ĸ��������ͬת�ɲ�ͬ
				differ++;
			}
			count[s[i + pLen] - 'a']++;				//��ĸ����-1

			if (differ == 0) {
				ans.push_back(i + 1);
			}
		}
		return ans;
	}
};

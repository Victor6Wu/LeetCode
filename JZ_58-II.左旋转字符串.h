//�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
#include<string>
using namespace std;

//����1�����ַ����ֳ�����
class Solution1 {
public:
    string reverseLeftWords(string s, int n) {
        string s1 = s.substr(0, n);
        string s2 = s.substr(n, s.size() - n);
        return s2 + s1;
    }
};

//����2����ε���reverse
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
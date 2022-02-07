//����һ���ַ��� s �������ת�ַ����е����� ���� ��
//���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����
//���㷵��һ����ת s �е���˳���õ����ո��������ַ�����
#include<string>
using namespace std;

class Solution {
public:
    //ɾ������Ŀո�
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0;
        //ɾ��ͷ���ո���ν��ɾ�����ǽ���ָ�����Ų����
        while (fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }

        //ɾ���м�����Ŀո�
        for (; fastIndex < s.size(); fastIndex++) {
            //ֻ�пո���������ʱ��������ɾ����
            if (fastIndex > 1 && s[fastIndex] == ' ' && s[fastIndex - 1] == s[fastIndex]) {
                continue;
            }
            //������Ҫ����ָ�봦���ַ����ǵ���ָ�봦
            else {
                s[slowIndex++] = s[fastIndex];
            }
        }

        //ɾ���ַ�ĩβ�Ŀո���β��������֣���ͨ�ַ���һ���ո񣬶���ո�
        //������һ����ѭ����slowIndex - 1��λ�û����Ϊ' '
        if (slowIndex > 1 && s[slowIndex - 1] == ' ') {
            s.resize(slowIndex - 1);
        }
        else {
            s.resize(slowIndex);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);                   //ɾ������ո�
        reverse(s.begin(), s.end());            //��ת�����ַ���
        for (int i = 0; i < s.size(); i++) {    //�������ʷ�ת����Ϊ�Ѿ�ȡ��ͷβ�Ŀո����Ե�һ������Ĭ�ϴ�0��ʼ
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);      //����ע�⣬�⺯��reverse���õ�������ҿ�
            i = j;
        }
        return s;
    }
};
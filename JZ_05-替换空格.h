//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
#include<string>
using namespace std;

//����1�������µ�����
class Solution1 {
public:
    string replaceSpace(string s) {
        string ans;
        for (char it : s) {
            if (it != ' ') {
                ans.push_back(it);
            }
            else {
                ans += "%20";
            }
        }
        return ans;
    }
};

//����2���������飬�Ӻ���ǰ���
class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size() - 1;
        //ͳ�ƿո���
        int count = 0;
        for (char it : s) {
            if (it == ' ') {
                count++;
            }
        }

        //�����ַ���
        s.resize(s.size() + count * 2);
        int newSize = s.size() - 1;
        //�������
        while (oldSize != newSize) {
            if (s[oldSize] != ' ') {
                s[newSize] = s[oldSize];
            }
            else {
                s[newSize] = '0';
                s[newSize - 1] = '2';
                s[newSize - 2] = '%';
                newSize -= 2;
            }
            oldSize--;
            newSize--;
        }
        return s;
    }
};
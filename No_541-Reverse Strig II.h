//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ�
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ��.
#include<string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k < s.size()) {         //�жϹ�����k��
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            //���򣬲���k������תʣ������
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
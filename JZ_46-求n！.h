//�� 1+2+...+n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

//���淽��
class Solution1 {
public:
    int sumNums(int n) {
        if (n == 1) return 1;
        return sumNums(n - 1) + n;
    }
};

//�������� && ���ص�
class Solution2 {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�� ��+������-������*������/�� ����������š�

//��λΪ����ȡ����򡱣���λȡ�������㡱
class Solution1 {
public:
    int add(int a, int b) {
        while (b) {//�Խ�λ����ѭ������һ�ε�b���Կ����ǵ�0�ν���Ľ�λ�������1�ε�����
            int carry = a & b; // ���� ��λ
            a = a ^ b; // ���� ��λ
            b = (unsigned)carry << 1;       //���ֵĽ�λ������һ�ּ���
        }
        return a;
    }
};

class Solution {
public:
    int add(int a, int b) {
        return b ? add(a ^ b, (a & b) << 1) : a;
    }
};
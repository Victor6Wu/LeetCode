//����һ���޷�������ͳ��������Ʊ�ʾ�С�1�����ֵĴ���
#include<stdint.h>

//����1����λ��
int count1(uint32_t x) {
    int count = 0;
    while (x) {
        if (x & 0x1)
            ++count;
        x = (x >> 1);
    }
    return count;
}

//ȥ1��
int count2(uint32_t x) {
    int count = 0;
    //x & (x - 1)�������x�����������ұߵ�1��ֱ��x��Ϊ0
    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}

//输入一个无符号数，统计其二进制表示中“1”出现的次数
#include<stdint.h>

//方法1：移位法
int count1(uint32_t x) {
    int count = 0;
    while (x) {
        if (x & 0x1)
            ++count;
        x = (x >> 1);
    }
    return count;
}

//去1法
int count2(uint32_t x) {
    int count = 0;
    //x & (x - 1)将会减少x二进制中最右边的1，直至x变为0
    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}

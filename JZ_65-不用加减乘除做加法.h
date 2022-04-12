//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

//本位为两数取“异或”，进位取“与运算”
class Solution1 {
public:
    int add(int a, int b) {
        while (b) {//对进位进行循环，第一次的b可以看成是第0次结果的进位，参与第1次的运算
            int carry = a & b; // 计算 进位
            a = a ^ b; // 计算 本位
            b = (unsigned)carry << 1;       //本轮的进位留到下一轮计算
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
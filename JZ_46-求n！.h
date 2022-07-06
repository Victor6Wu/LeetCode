//求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

//常规方法
class Solution1 {
public:
    int sumNums(int n) {
        if (n == 1) return 1;
        return sumNums(n - 1) + n;
    }
};

//巧妙利用 && 的特点
class Solution2 {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
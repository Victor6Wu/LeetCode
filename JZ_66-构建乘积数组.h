//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
//即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
#include<vector>
using namespace std;

//本题明确指出不能使用除非，其实帮助我们扫除了一个陷阱：数组中有0的时候，采用先求乘积再除的方式是有问题的
//方法1：借用2 * O(N)的空间复杂度，B[i]其实可以看成A[i]左右两次乘积结果的乘积，因此可以构建两个数组分布表示位置i左右两侧的乘积结果
//时间复杂度3 * O(N)
class Solution1 {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> left(n, 1);     //位置0左侧没有数字，可以认为乘积结果为1
        vector<int> right(n, 1);
        vector<int> B(n);
        //从位置1向右更新数组left
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * a[i - 1];
        }
        //从最后一个位置向左更新数组rigth
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i + 1];
        }

        //其实不创建数组B也可，直接在left或者right的基础上修改，作为输出
        for (int i = 0; i < n; i++) {
            B[i] = left[i] * right[i];
        }
        return B;
    }
};

//方法2：还是方法1的思路，不过只用一个数组，额外的空间复杂度为O(1)
class Solution2 {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> B(n, 1);
        for (int i = 1; i < n; i++) {
            B[i] = B[i - 1] * a[i - 1];
        }
        int pre = 1;
        for (int i = n - 1; i >= 0; i--) {
            B[i] = B[i] * pre;
            pre *= a[i];
        }
        return B;
    }
};
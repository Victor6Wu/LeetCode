//����һ���������� nums ������ nums ����Ϊ �ڶ����� �� ������еĳ��� ��
#include<vector>
using namespace std;

//̰�ķ������Ͻ����ѡ�񡰷塱�򡰹ȡ�������
class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int prevdiff = nums[1] - nums[0];
        int ret = prevdiff != 0 ? 2 : 1;       //���ͷ���������Ԫ�أ�retҪ��1��ʼ����
        for (int i = 2; i < n; i++) {   
            int diff = nums[i] - nums[i - 1];
            //�������ϵĹ���Ԫ���Լ���ˮƽ��Ԫ��
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                ret++;
                prevdiff = diff;
            }
        }
        return ret;
    }
};

//��̬�滮��
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            }
            else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

//��̬�滮�Ż�
class Solution3 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = max(up, down + 1);     //up = down + 1;    ��ѭ���Ĺ����У�down��up��ֵ�������1
            }
            else if (nums[i] < nums[i - 1]) {
                down = max(up + 1, down);   //down = up + 1;
            }
        }
        return max(up, down);
    }
};
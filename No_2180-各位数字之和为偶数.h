//����һ�������� num ������ͳ�Ʋ����� С�ڻ���� num �Ҹ�λ����֮��Ϊ ż�� ������������Ŀ��
//�������� ��λ����֮�� ��������λ�ϵĶ�Ӧ������ӵĽ����
#include<vector>
using namespace std;

//��̬�滮��
class Solution {
public:
    bool isOven(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return (sum % 2) == 0 ? true : false;
    }

    int countEven(int num) {
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 1; i <= num; i++) {
            if (isOven(i)) dp[i] = dp[i - 1] + 1;
            else dp[i] = dp[i - 1];
        }
        return dp[num];
    }
};

//��̬�滮��˼�룬���ǿռ临�Ӷ�O(1)����
class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 2; i <= num; i++) {
            if (check(i))res++;
        }
        return res;
    }

public:
    bool check(int num) {
        int checkNum = 0;
        while (num > 0) {
            checkNum = checkNum + (num % 10);
            num /= 10;
        }
        return checkNum % 2 == 0;
    }
};
//����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����
//һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����
#include<vector>
#include<string>
using namespace std;

//��̬�滮����������쳲��������У�ֻ����һ����Ҫ������
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        if (str.size() <= 1) return str.size();
        vector<int> dp(str.size() + 1);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= str.size(); i++) {
            int index = stoi(str.substr(i - 2, 2));
            if (index >= 10 && index <= 25) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[str.size()];
    }
};
//�ռ��Ż�
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        if (str.size() <= 1) return str.size();
        int first = 1, second = 1;
        int cur;
        for (int i = 2; i <= str.size(); i++) {
            int index = stoi(str.substr(i - 2, 2));
            if (index >= 10 && index <= 25) {
                cur = first + second;
                first = second;
                second = cur;
            }
            else {
                cur = second;
                first = second;
                second = cur;
            }
        }
        return second;
    }
};
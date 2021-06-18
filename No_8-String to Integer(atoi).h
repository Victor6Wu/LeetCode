//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
#include<string>
using namespace std;

class Solution {
public:
	//solution 1:�Ա���򣬴�����΢����
	int myAtoi1(string s) {
		int sign = 0;		//���ڱ������ֵ�����
		long long ans = 0;		//��ʼ��С
		int begin = 0;			//��ʼλ��
		int n = s.size();
		for (; begin < n; ++begin) {
			if (s[begin] == ' ') continue;
			else if (s[begin] == '-') {
				sign = -1;		//����Ϊ��
				++begin;
				break;
			}
			else if (s[begin] == '+') {
				sign = 1;		//����Ϊ��
				++begin;
				break;
			}
			else if (int(s[begin]) >= 48 && int(s[begin]) <= 57) {
				sign = 1;
				break;
			}
			else return ans;
		}
		//����߽�
		long long bounder = INT_MAX ;
		if (sign == 0|| begin == n) return ans;
		if (sign == -1) bounder += 1;
		//��ʼ�ӵ�ǰi����
		while (begin < n && int(s[begin]) >= 48 && int(s[begin]) <= 57) {
			if (10 * ans + int(s[begin]) - 48 <= bounder) {
				ans = 10 * ans + int(s[begin]) - 48;
			}
			else return sign == 1 ? 2147483647 : -2147483648;
			begin++;
		}
		//���ؽ��
		if (sign == 1) {
			return ans;
		}
		else {
			return -ans;
		}
	}

	//solution 2:�����Ż�������Ҫ��long long���ͣ��Ƚϴ�С��ʱ��ֻҪ��������ͬ����10�����ɱ������
	int myAtoi2(string s) {
		int ans = 0;
		int i = 0;
		int sign = 1;		//Ĭ��Ϊ+
		//�Թ�ǰ�˿ո�
		while (s[i] == ' ') {
			++i;
		}
		if (s[i] == '-') sign = -1;		//�޸ķ���
		if (s[i] == '-' || s[i] == '+') ++i;	//����λ�Թ�,���������ֿ�ʼ
		while (i < s.size() && isdigit(s[i])) {
			int num = s[i] - '0';		//ȡ����ǰ�ַ�ת��������
			
			//��ǰ�ж��Ƿ�����
			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && num > 7)) {		//ע��������num>7������8
				return sign > 0 ? INT_MAX : INT_MIN;
			}
			//ȷ����������ˣ��ټӵ������
			ans = 10 * ans + num;
			i++;
		}
		return sign > 0 ? ans : -ans;
	}
};
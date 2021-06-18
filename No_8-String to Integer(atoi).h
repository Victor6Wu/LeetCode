//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
#include<string>
using namespace std;

class Solution {
public:
	//solution 1:自编程序，代码略微冗余
	int myAtoi1(string s) {
		int sign = 0;		//用于表述数字的正负
		long long ans = 0;		//初始大小
		int begin = 0;			//起始位置
		int n = s.size();
		for (; begin < n; ++begin) {
			if (s[begin] == ' ') continue;
			else if (s[begin] == '-') {
				sign = -1;		//设置为负
				++begin;
				break;
			}
			else if (s[begin] == '+') {
				sign = 1;		//设置为正
				++begin;
				break;
			}
			else if (int(s[begin]) >= 48 && int(s[begin]) <= 57) {
				sign = 1;
				break;
			}
			else return ans;
		}
		//定义边界
		long long bounder = INT_MAX ;
		if (sign == 0|| begin == n) return ans;
		if (sign == -1) bounder += 1;
		//开始从当前i计数
		while (begin < n && int(s[begin]) >= 48 && int(s[begin]) <= 57) {
			if (10 * ans + int(s[begin]) - 48 <= bounder) {
				ans = 10 * ans + int(s[begin]) - 48;
			}
			else return sign == 1 ? 2147483647 : -2147483648;
			begin++;
		}
		//返回结果
		if (sign == 1) {
			return ans;
		}
		else {
			return -ans;
		}
	}

	//solution 2:代码优化，不需要用long long类型，比较大小的时候只要将两个数同除以10，即可避免溢出
	int myAtoi2(string s) {
		int ans = 0;
		int i = 0;
		int sign = 1;		//默认为+
		//略过前端空格
		while (s[i] == ' ') {
			++i;
		}
		if (s[i] == '-') sign = -1;		//修改符号
		if (s[i] == '-' || s[i] == '+') ++i;	//符号位略过,期望从数字开始
		while (i < s.size() && isdigit(s[i])) {
			int num = s[i] - '0';		//取出当前字符转换成数字
			
			//提前判断是否会溢出
			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && num > 7)) {		//注意这里是num>7，不是8
				return sign > 0 ? INT_MAX : INT_MIN;
			}
			//确定不会溢出了，再加到结果上
			ans = 10 * ans + num;
			i++;
		}
		return sign > 0 ? ans : -ans;
	}
};
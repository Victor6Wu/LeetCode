//Given an integer, convert it to a roman numeral.
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	//solution 1:自编程序，利用哈希表
	string intToRoman1(int num) {
		//初始化哈希表
		map<int, string> table;
		table[1] = "I";
		table[5] = "V";
		table[10] = "X";
		table[50] = "L";
		table[100] = "C";
		table[500] = "D";
		table[1000] = "M";
		table[4] = "IV";
		table[9] = "IX";
		table[40] = "XL";
		table[90] = "XC";
		table[400] = "CD";
		table[900] = "CM";

		string ans;
		//创建商、余数，除数
		int quotient, remainder = num, divisor = 1000;
		while (divisor != 0) {
			quotient = remainder / divisor;
			remainder = remainder % divisor;
			if (quotient > 0) {
				string str = table[quotient * divisor];
				if (!str.empty()) {
					ans += str;
				}
				else {
					if (quotient > 5) {
						ans = ans + table[5 * divisor] + string((quotient - 5), table[divisor][0]);
					}
					else {
						ans = ans + string(quotient, table[divisor][0]);
					}
				}
			}
			divisor /= 10;
		}
		return ans;
	}

	//solution 2：枚举法，将所有特殊情况作为节点，从大到小进行比较
    string GetStr(int& num)
    {
        if (num >= 1000)
        {
            num -= 1000;
            return "M";
        }
        else if (num >= 900)
        {
            num -= 900;
            return "CM";
        }
        else if (num >= 500)
        {
            num -= 500;
            return "D";
        }
        else if (num >= 400)
        {
            num -= 400;
            return "CD";
        }
        else if (num >= 100)
        {
            num -= 100;
            return "C";
        }
        else if (num >= 90)
        {
            num -= 90;
            return "XC";
        }
        else if (num >= 50)
        {
            num -= 50;
            return "L";
        }
        else if (num >= 40)
        {
            num -= 40;
            return "XL";
        }
        else if (num >= 10)
        {
            num -= 10;
            return "X";
        }
        else if (num >= 9)
        {
            num -= 9;
            return "IX";
        }
        else if (num >= 5)
        {
            num -= 5;
            return "V";
        }
        else if (num >= 4)
        {
            num -= 4;
            return "IV";
        }
        else
        {
            num -= 1;
            return "I";
        }
    }
    string intToRoman2(int num) {
        string res;
        while (num > 0)
        {
            res += GetStr(num);
        }
        return res;
    }

    //solution 3:类似于枚举法，将每种情况比较大小，减去值
    string intToRoman(int num) {
        string roman;
        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }

    //solution 4:类似于solution1自编代码+solution3枚举法，按位枚举所有情况，
    string intToRoman4(int num) {
        const string thousands[] = { "", "M", "MM", "MMM" };
        const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

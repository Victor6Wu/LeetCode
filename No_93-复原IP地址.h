//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
#include<vector>
#include<string>
using namespace std;

//方法1：在分割的过程中就限制每一段数值在[0,255]之间，还有考虑不能是0xx这种格式
class Solution1 {
private:
    vector<string> result;
    string tmp;
public:
    void backtracking(string& s, int startIndex, int count) {   //startIndex用于记录当前段起点，count记录已经产生了几段地址
        if (count == 4) {
            if (startIndex == s.size()) {           //只有s被刚好分成4段才算有效IP，如果还剩余字符没参与分割则不算
                result.push_back(tmp);
            }
            return;
        }

        for (int i = 1; startIndex + i <= s.size() && i <= 3; i++) {     //一段最长为3个字符，i表示一段，即seg的长
            string seg = s.substr(startIndex, i);       //取出子段
            if (i == 3 && stoi(seg) > 255) {            //判断是否超出范围只用在3位数的情况考虑
                break;
            }

            count += 1;             //段数+1
            if (count < 4) {        //判断是否前3段   
                seg += ".";         //第四段后面是不用加'.'的
            }
            tmp += seg;
            backtracking(s, startIndex + i, count);
            //回溯
            for (int j = 0; j < seg.size(); j++) {
                tmp.pop_back();
            }
            count--;
            //判断当前是不是'0'，如果是，后面的循环就不需要了
            if (seg[0] == '0' && i == 1) {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};

//方法2：分割出所有可能的组合，将符合有效IP的返回

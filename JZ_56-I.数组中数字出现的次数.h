#pragma once
#include<vector>
using namespace std;

//本题的知识储备：
//1.两个相同的数取“异或”得到0
//2.0与其他非零的数取“异或”得到数本身
//3.异或结果为1表示两数不同，0表示两数相同
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;
		//整个数组进行异或，得到两个只出现1次的数的异或结果
		for (const int& num : nums) {
			ret ^= num;
		}

		//根据两个只出现1次的数的异或结果找出两个数最低的不相等位（找到为1的位），用于后续的分组操作
		int div = 1;
		while ((div & ret) == 0) div <<= 1;//左移来判断高位，注意：要用<<=，=一定不能丢

		//分两组进行异或，即想要的结果
		int a = 0, b = 0;
		for (const int& num : nums) {
			//根据上一步得到的位，对应num是0还是1进行分组
			if ((num & div) == 0) {		
				a ^= num;
			}
			else b ^= num;
		}
		return { a, b };
	}
};
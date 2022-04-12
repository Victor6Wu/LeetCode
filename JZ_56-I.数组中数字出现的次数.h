#pragma once
#include<vector>
using namespace std;

//�����֪ʶ������
//1.������ͬ����ȡ����򡱵õ�0
//2.0�������������ȡ����򡱵õ�������
//3.�����Ϊ1��ʾ������ͬ��0��ʾ������ͬ
class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;
		//�������������򣬵õ�����ֻ����1�ε����������
		for (const int& num : nums) {
			ret ^= num;
		}

		//��������ֻ����1�ε�����������ҳ���������͵Ĳ����λ���ҵ�Ϊ1��λ�������ں����ķ������
		int div = 1;
		while ((div & ret) == 0) div <<= 1;//�������жϸ�λ��ע�⣺Ҫ��<<=��=һ�����ܶ�

		//�����������򣬼���Ҫ�Ľ��
		int a = 0, b = 0;
		for (const int& num : nums) {
			//������һ���õ���λ����Ӧnum��0����1���з���
			if ((num & div) == 0) {		
				a ^= num;
			}
			else b ^= num;
		}
		return { a, b };
	}
};
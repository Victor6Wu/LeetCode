#pragma once
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//solution 1: �����ⷨ���ȹ���һ���򵥵ĳ�Ա���������ڼ����������߼�����,ʱ�临�Ӷ�O(n^2)��Ч��̫��
	int computeArea(int index_num1, int value_num1, int index_num2, int value_num2) {
		return (index_num2 - index_num1) * min(value_num1, value_num2);
	}

	int maxArea1(vector<int>& height) {
		//vector<int> resultSave;
		int ans = 0;
		int n = height.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ans = max(ans, computeArea(i, height[i], j, height[j]));
				//resultSave.push_back(computeArea(i, height[i], j, height[j]));
			}
		}
		//auto maxArea = max_element(resultSave.begin(), resultSave.end());
		//return *maxArea;
		return ans;
	}

	//solution 2: ˫ָ�뷨���뱩���ⷨ���������ȫ�����������ͬ��˫ָ�뷨��ȥ��һ����Ȼ�����ܵĴ𰸣����ڼ������
	//������˼·�ǣ�˫ָ��ÿ���ƶ��̵��Ǹ��������Ͱѹ̶��̵ģ��ƶ�������һ���ֵĽ��ֱ��������
	int maxArea2(vector<int>& height) {
		int left = 0, right = height.size()-1;
		int ans = 0;
		while (left < right) {
			int area = (right - left) * min(height[left], height[right]);
			ans = max(ans, area);
			if (height[left] <= height[right]) {
				++left;
			}
			else {
				--right;
			}
		}
		return ans;
	}
};
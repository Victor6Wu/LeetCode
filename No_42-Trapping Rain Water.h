#pragma once
//Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it can trap after raining.
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	//solution 1: �����ⷨ��ÿ��λ�õ�ʢˮ���������������ֵ�н�С���Ǹ����� 
	int trap1(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int leftMax = 0, rightMax = 0;
			//�˴�ѭ��ʱ����iΪ���������������ֵ�����������i��
			//��������(min(leftMax, rightMax) - height[i])Ϊ���������
			for (int j = i; 0 <= j; --j) {
				leftMax = max(leftMax, height[j]);
			}
			for (int j = i; j < n; ++j) {
				rightMax = max(rightMax, height[j]);
			}
			ans = ans + (min(leftMax, rightMax) - height[i]);
		}
		return ans;
	}

	//solution 2����̬�滮��������solution 1 ��˼·����ǰ��ÿ��λ�õ��������ֵ����������������飬���ֱ�Ӽ������
	int trap2(vector<int>& height) {
		int n = height.size();
		if (n < 3) return 0;
		int ans = 0;
		vector<int> leftMax(n), rightMax(n);
		//����������ֵ����
		leftMax[0] = height[0];
		for (int i = 1; i < n; ++i) {
			leftMax[i] = max(leftMax[i - 1], height[i]);
		}
		//�����ұ����ֵ����
		rightMax[n-1] = height[n-1];
		for (int i = n-2; 0 <= i; --i) {
			rightMax[i] = max(rightMax[i + 1], height[i]);
		}
		//����ʢˮ��
		for (int i = 0; i < n; ++i) {
			ans = ans + (min(leftMax[i], rightMax[i]) - height[i]);
		}
		return ans;
	}

	//solution 3: ջ�����ݼ�ջ
	int trap3(vector<int>& height) {
		int n = height.size();
		int ans = 0, current = 0;
		stack<int> st;
		while (current < n) {
			while (!st.empty() && height[current] > height[st.top()]) {
				//��Ϊ���ӵĵ�
				int top = st.top();			
				st.pop();
				//������ջ�Ƿ�Ϊ�գ���������ջ���������ӵ���߽�
				if (st.empty())
					break;
				int distance = current - st.top() - 1;
				int bounded_height = min(height[current], height[st.top()]) - height[top];
				ans = ans + bounded_height * distance;
			}
			st.push(current++);
		}
		return ans;
	}

	//solution 4: ˫ָ�뷨���̶��ϸߵ�ָ�룬�ƶ���ָ�벢����ÿ��ʢˮ����������֮ǰ�̶���ָ��ʱ���ٽ����ƶ�
	int trap4(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0;
		//��ʼ���������ֵ
		int leftMax = 0, rightMax = 0;
		while (left < right) {
			if (height[left] < height[right]) {
				height[left] >= leftMax ? (leftMax = height[left]) : ans += (leftMax - height[left]);
				++left;
			}
			else {
				height[right] >= rightMax ? (rightMax = height[right]) : ans += (rightMax - height[right]);
				--right;
			}
		}
		return ans;
	}
};
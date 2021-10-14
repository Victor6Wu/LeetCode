//A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
//Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	//solution 1:����������У���߽���ѣ��ұ߽���ѣ����ݶѶ��仯���ȷ���ؼ���
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//�Ƚ�����ĳ����ұ߽����ʽ������������߽�߶��ø�����ʾ
		multiset<pair<int, int>> vec;
		for (auto& b : buildings) {
			vec.insert({ b[0],-b[2] });
			vec.insert({ b[1],b[2] });
		}

		//�������ѡ�
		multiset<int> Q;
		Q.insert(0);	//�ȴ����ʼ�߶�0
		int preMax = 0;	//��ʼ���ֵ

		vector<vector<int>> res;
		for (auto& it : vec) {		//ɨ�����б߽�
			if (it.second < 0) {	//��߽����
				Q.insert(-it.second);	
			}
			else		//�ұ߽����
			{
				Q.erase(Q.find(it.second));
			}
			int curMax = *Q.rbegin();
			if (curMax != preMax) {		//���ֵ�����仯���йؼ������
				res.push_back({ it.first,curMax });
				preMax = curMax;		//����֮ǰ�����ֵ
			}
		}
		return res;
	}
};
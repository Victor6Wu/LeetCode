//�����㷨
#include<vector>
using namespace std;

//Dijkstra�㷨������̰���㷨��˼�룬�ֳ���ѡ�ڵ��δѡ�ڵ������֣�
//1.��㱾����λ����ѡ�ڵ�ģ������ڵ�λ��δѡ�ڵ㣻
//2.����ʼ�ڵ����ɨ�裬�޸�ͼ��������������δѡ���ֵĽڵ�ľ��룻
//3.ÿ�ζ�����δѡ�ڵ�����ѡ������С���Ǹ��ڵ������ѡ�ڵ㣬������Ϊ��ʼ�ڵ����ɨ�裬�޸ľ��룻
//4.���ظ�2��3������ѡ�������С�Ľڵ㣻

//�������֮����ֱ�����ӣ���ͼ�б���Ϊ-1�� i-iΪ0
vector<int> Dijkstra(vector<vector<int>>& graph, int startVertex) {
	//��ʼ��
	int n = graph.size();
	vector<int> result(n, -1), notfound(n);
	result[startVertex] = 0; //-1��ʾδ�ҵ�
	for (int i = 0; i < n; i++) {
		notfound[i] = graph[startVertex][i];
	}
	notfound[startVertex] = -1; //-1��ʾ����Ѿ������
	for (int i = 1; i < n; i++) { //һ�μ����һ��ֵ����Ҫ����n-1�α���
		int minindex;
		int minDis = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (notfound[j] != -1 && notfound[j] < minDis) {
				minDis = notfound[j];
				minindex = j;
			}
		}
		//�������i��resultֵ
		result[minindex] = minDis;
		notfound[minindex] = -1;
		//����notfound[j]
		for (int j = 0; j < n; j++) {
			if (result[j] == -1 && graph[minindex][j] > 0) {
				int newDis = graph[minindex][j] + result[minindex];
				if (newDis < notfound[j] || notfound[j] == -1) {
					notfound[j] = newDis;
				}
			}
		}
	}
	return result;
}

//Floyd
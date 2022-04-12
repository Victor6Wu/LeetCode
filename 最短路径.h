//两种算法
#include<vector>
using namespace std;

//Dijkstra算法，基于贪心算法的思想，分成已选节点和未选节点两部分；
//1.起点本身是位于已选节点的，其他节点位于未选节点；
//2.以起始节点进行扫描，修改图中与其相邻且在未选部分的节点的距离；
//3.每次都是在未选节点里面选距离最小的那个节点加入已选节点，再以其为起始节点进行扫描，修改距离；
//4.再重复2、3操作，选择距离最小的节点；

//如果两点之间无直接连接，在图中表现为-1， i-i为0
vector<int> Dijkstra(vector<vector<int>>& graph, int startVertex) {
	//初始化
	int n = graph.size();
	vector<int> result(n, -1), notfound(n);
	result[startVertex] = 0; //-1表示未找到
	for (int i = 0; i < n; i++) {
		notfound[i] = graph[startVertex][i];
	}
	notfound[startVertex] = -1; //-1表示结果已经计算出
	for (int i = 1; i < n; i++) { //一次计算出一个值，需要进行n-1次遍历
		int minindex;
		int minDis = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (notfound[j] != -1 && notfound[j] < minDis) {
				minDis = notfound[j];
				minindex = j;
			}
		}
		//计算出第i个result值
		result[minindex] = minDis;
		notfound[minindex] = -1;
		//更新notfound[j]
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
//����  xstart �� x �� xend���������ᱻ��������������Ĺ���������û�����ơ� ����һ�������֮�󣬿������޵�ǰ����
//�������ҵ�ʹ����������ȫ��������������Ĺ�������С������
//����һ������ points ������ points [i] = [xstart,xend] �������������������������������С��������
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    //�������򷽷�
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;        //��ʼ����һ֧��
        //�ӵڶ�������ʼѭ������ǰ��������顱���бȽ�
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) res++;//�����ǰ�������߽�����ϸ�������ұ߽磨�ص������ұ߽磩���ض����ص�
            else {
                //���ǵ��ص������ж���������ǰ��������һ�����ص�ʱҪ�������ұ߽�
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
};
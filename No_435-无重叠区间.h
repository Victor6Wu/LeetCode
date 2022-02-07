//����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
#include<vector>
#include<algorithm>
using namespace std;

//����1���ұ߽�����
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;      //ͳ�ƶ�������ĸ��������ٻ���һ���������
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[i - 1][1]) count++;
            else {
                intervals[i][1] = intervals[i - 1][1];
            }
        }
        return intervals.size() - count;
    }
};

//����2���޸�No_452�Ĵ���
class Solution {
private:
    //�������򷽷�
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;        //��ʼ����һ֧��
        //�ӵڶ�������ʼѭ������ǰ��������顱���бȽ�
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] >= points[i - 1][1]) res++;//�����ǰ�������߽�����ϸ�������ұ߽磨�ص������ұ߽磩���ض����ص�
            else {
                //���ǵ��ص������ж���������ǰ��������һ�����ص�ʱҪ�������ұ߽�
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return points.size() - res;
    }
};
//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
#include<vector>
#include<algorithm>
using namespace std;

//方法1：右边界排序
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;      //统计独立区间的个数，至少会有一个区间独立
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[i - 1][1]) count++;
            else {
                intervals[i][1] = intervals[i - 1][1];
            }
        }
        return intervals.size() - count;
    }
};

//方法2：修改No_452的代码
class Solution {
private:
    //定义排序方法
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;        //初始至少一支箭
        //从第二个气球开始循环，与前面的气球“组”进行比较
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] >= points[i - 1][1]) res++;//如果当前气球的左边界大于上个气球的右边界（重叠区的右边界），必定不重叠
            else {
                //考虑到重叠与否的判断条件，当前气球与上一个组重叠时要更新其右边界
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return points.size() - res;
    }
};
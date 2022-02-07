//满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。
//我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
//给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    //定义排序方法
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;        //初始至少一支箭
        //从第二个气球开始循环，与前面的气球“组”进行比较
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) res++;//如果当前气球的左边界大于上个气球的右边界（重叠区的右边界），必定不重叠
            else {
                //考虑到重叠与否的判断条件，当前气球与上一个组重叠时要更新其右边界
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
};
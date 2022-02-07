//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
//如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
//你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;      //已经满足了的孩子
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int ateCookie = -1; //最后一次用过的饼干
        for (int i = 0; i < g.size(); i++) {    //从小到大遍历孩子
            for (int j = ateCookie + 1; j < s.size(); j++) {    //从小到大找合适的饼干
                if (s[j] >= g[i]) {
                    count++;
                    s[j] = -1;
                    ateCookie = j;
                    break;
                }
            }
        }
        return count;
    }
};
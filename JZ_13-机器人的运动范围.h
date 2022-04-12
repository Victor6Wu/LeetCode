//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
//也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
//但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
#include<vector>
#include<queue>
using namespace std;


//dfs
class Solution1 {
private:
    int rows;
    int cols;
    int ans;
    int K;
    bool morethanK(int i, int j, int k) {
        int sum = 0;
        while (i > 0) {
            sum += (i % 10);
            i /= 10;
        }
        while (j > 0) {
            sum += (j % 10);
            j /= 10;
        }
        return sum > k;
    }

    void dfs(vector<vector<bool>> &grids, int i, int j) {
        //判断是否超出范围或者已经被搜索过
        if (i < 0 || i >= rows || j < 0 || j >= cols || grids[i][j]) return;
        //判断当前坐标位数和是否大于K
        if (morethanK(i, j, K)) return;
        
        //当前网格可到达
        ans++;
        grids[i][j] = true;
        dfs(grids, i - 1, j);
        dfs(grids, i + 1, j);
        dfs(grids, i, j - 1);
        dfs(grids, i, j + 1);
    }
public:
    int movingCount(int m, int n, int k) {
        rows = m;
        cols = n;
        K = k;
        vector<vector<bool>> grids(m, vector<bool>(n, false));      //保证能到达的点不被重复记录
        dfs(grids, 0, 0);
        return ans;
    }
};
//dfs存在的问题是，grids数组只能保证能到达的点不被重复计数，但是不能到达的点会有可能多次访问

//bfs，广度搜索的好处是，每次只往右或下考虑，每个点只会被访问一次
class Solution2 {
    // 计算 x 的数位之和
    int get(int x) {
        int res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int, int> > Q;       //和树的层序遍历类似，bfs难免要用到队列
        // 向右和向下的方向数组
        int dx[2] = { 0, 1 };
        int dy[2] = { 1, 0 };
        vector<vector<int> > vis(m, vector<int>(n, 0));     //用于表示该位置是否被访问过
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();        //取出一个满足条件的点
            Q.pop();
            for (int i = 0; i < 2; ++i) {    //遍历该点的右边点、下边点
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                //超出范围或访问过或大于k
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;            //只要访问过就置为1 
                ans++;
            }
        }
        return ans;
    }
};
//������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
//Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
//�������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
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
        //�ж��Ƿ񳬳���Χ�����Ѿ���������
        if (i < 0 || i >= rows || j < 0 || j >= cols || grids[i][j]) return;
        //�жϵ�ǰ����λ�����Ƿ����K
        if (morethanK(i, j, K)) return;
        
        //��ǰ����ɵ���
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
        vector<vector<bool>> grids(m, vector<bool>(n, false));      //��֤�ܵ���ĵ㲻���ظ���¼
        dfs(grids, 0, 0);
        return ans;
    }
};
//dfs���ڵ������ǣ�grids����ֻ�ܱ�֤�ܵ���ĵ㲻���ظ����������ǲ��ܵ���ĵ���п��ܶ�η���

//bfs����������ĺô��ǣ�ÿ��ֻ���һ��¿��ǣ�ÿ����ֻ�ᱻ����һ��
class Solution2 {
    // ���� x ����λ֮��
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
        queue<pair<int, int> > Q;       //�����Ĳ���������ƣ�bfs����Ҫ�õ�����
        // ���Һ����µķ�������
        int dx[2] = { 0, 1 };
        int dy[2] = { 1, 0 };
        vector<vector<int> > vis(m, vector<int>(n, 0));     //���ڱ�ʾ��λ���Ƿ񱻷��ʹ�
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();        //ȡ��һ�����������ĵ�
            Q.pop();
            for (int i = 0; i < 2; ++i) {    //�����õ���ұߵ㡢�±ߵ�
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                //������Χ����ʹ������k
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;            //ֻҪ���ʹ�����Ϊ1 
                ans++;
            }
        }
        return ans;
    }
};
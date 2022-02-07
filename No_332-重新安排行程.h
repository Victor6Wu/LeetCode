//给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
//是的安排是从"JFK"出发，能够将所有机票串起来
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;

//自编代码，回溯思想，用set实现获得字典序最小，会超时
class Solution1 {
private:
    set<vector<string>> ans;
    vector<string> tmp;
public:
    void backtracking(vector<vector<string>>& tickets, int count, vector<bool>& used) {
        if (count == tickets.size()) {
            ans.insert(tmp);
            return;
        }

        for (int i = 0; i < tickets.size(); i++) {
            if (used[i] == true) continue;          //用过的票就直接跳过
            if (count == 0) {                       //第一张票必须选从'JFK'出发的
                if (tickets[i][0].compare("JFK") != 0) continue;
                tmp.push_back(tickets[i][0]);
                tmp.push_back(tickets[i][1]);
                count++;
                used[i] = true;
                backtracking(tickets, count, used);
                used[i] = false;
                count--;
                tmp.pop_back();
                tmp.pop_back();
                continue;
            }
            //对于非第一张票，就与tmp的最后达到站比较
            if (tickets[i][0] == tmp.back()) {
                tmp.push_back(tickets[i][1]);
                count++;
                used[i] = true;
                backtracking(tickets, count, used);
                used[i] = false;
                count--;
                tmp.pop_back();
            }
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);          //记录哪些票被用过了
        backtracking(tickets, 0, used);
        auto it = *ans.begin();
        return it;
    }
};

//借用哈希表记录出发地到目的地的所有映射
class Solution2 {
private:
    unordered_map<string, map<string, int>> targets;    //统计所有机票中的起点和终点的映射
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) {
            return true;
        }
        //循环上一次的终点作为起点时映射的终点
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {            //大于0表示从当前起点到终点的机票还有
                result.push_back(target.first);
                target.second--;
                //非常关键的一句：该回溯函数返回值是bool类型，如果下面的回溯函数能成功返回true，说明已经找到想要的树枝
                //也必然是最小字典序，因为targets[result[result.size() - 1]]是一个map，先去尝试的是字典序中最小的
                if (backtracking(ticketNum, result)) return true;
                target.second++;
                result.pop_back();
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;          
        for (auto& it : tickets) {
            targets[it[0]][it[1]]++;
        }
        result.push_back("JFK");        //起始点
        backtracking(tickets.size(), result);   //因为tickets被targets替代，需要一个终止条件
        return result;
    }
};
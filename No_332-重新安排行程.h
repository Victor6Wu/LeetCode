//����һ�ݺ����б� tickets ������ tickets[i] = [fromi, toi] ��ʾ�ɻ������ͽ���Ļ����ص㡣����Ը��г̽������¹滮����
//�ǵİ����Ǵ�"JFK"�������ܹ������л�Ʊ������
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;

//�Ա���룬����˼�룬��setʵ�ֻ���ֵ�����С���ᳬʱ
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
            if (used[i] == true) continue;          //�ù���Ʊ��ֱ������
            if (count == 0) {                       //��һ��Ʊ����ѡ��'JFK'������
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
            //���ڷǵ�һ��Ʊ������tmp�����ﵽվ�Ƚ�
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
        vector<bool> used(tickets.size(), false);          //��¼��ЩƱ���ù���
        backtracking(tickets, 0, used);
        auto it = *ans.begin();
        return it;
    }
};

//���ù�ϣ���¼�����ص�Ŀ�ĵص�����ӳ��
class Solution2 {
private:
    unordered_map<string, map<string, int>> targets;    //ͳ�����л�Ʊ�е������յ��ӳ��
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) {
            return true;
        }
        //ѭ����һ�ε��յ���Ϊ���ʱӳ����յ�
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {            //����0��ʾ�ӵ�ǰ��㵽�յ�Ļ�Ʊ����
                result.push_back(target.first);
                target.second--;
                //�ǳ��ؼ���һ�䣺�û��ݺ�������ֵ��bool���ͣ��������Ļ��ݺ����ܳɹ�����true��˵���Ѿ��ҵ���Ҫ����֦
                //Ҳ��Ȼ����С�ֵ�����Ϊtargets[result[result.size() - 1]]��һ��map����ȥ���Ե����ֵ�������С��
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
        result.push_back("JFK");        //��ʼ��
        backtracking(tickets.size(), result);   //��Ϊtickets��targets�������Ҫһ����ֹ����
        return result;
    }
};
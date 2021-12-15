//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
//Each number in candidates may only be used once in the combination.
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx) {
        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        for (int i = idx; i < candidates.size() && target - candidates[i] >= 0; i++) {
            // 对于重复的数值段，后面的元素情况是前面的子集，按照循环的顺序，没有必要再对子集的情况进行考虑
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combine.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], ans, combine, i + 1);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
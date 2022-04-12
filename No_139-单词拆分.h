//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣�����ж��Ƿ���������ֵ��г��ֵĵ���ƴ�ӳ� s ��
//ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

//�����û��ݷ�Ҳ�ɽ�����������׳�ʱ
class Solution1 {
private:
    bool backtracking(const string& s, const unordered_set<string>& wordSet, int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtracking(s, wordSet, 0);
    }
};

//��ȫ��������
class Solution2 {
public:
    //�Ƚ��ַ���s��index��ǰ���ַ����ַ���str�ܷ�ƥ��
    bool compareStr(string& s, string& str, int index) { //index��ʾsʣ��ĿɱȽ��ַ���
        int n = str.size() - 1;
        while (n >= 0 && index > 0) {
            if (s[index - 1] != str[n]) return false;
            else {
                index--;
                n--;
            }
        }
        if (index <= 0 && n >= 0) return false;
        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);       //dp[j]��ʾ�ַ���s��λ��j֮ǰ���ַ�ƥ�����
        dp[0] = true;           //0֮ǰ����û���ַ����϶���true
        //iѭ����Ʒ��jѭ������
        for (int j = 0; j < s.size() + 1; j++) {
            for (int i = 0; i < wordDict.size(); i++) {
                if (j >= wordDict[i].size()) {
                    dp[j] = dp[j] || (dp[j - wordDict[i].size()] && compareStr(s, wordDict[i], j));
                }
            }
        }
        return dp[s.size()];
    }
};
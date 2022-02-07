//����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����
//���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> tmp;
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        if (j == 0) return true;
        else {
            while (i < j) {
                if (s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        }
    }

    void backtracking(string s, int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(tmp);
            return;
        }
        for (int endIndex = startIndex; endIndex < s.size(); endIndex++) {
            string str(s.begin() + startIndex, s.begin() + endIndex + 1);   //�˴�Ҫ+1������ҿ��ķ�ʽ��ʼ��
            if (isPalindrome(str)) {        //�˴������Ż�һ�£��ж��Ƿ���Ĵ���string&����������false������Ͳ���ȡsubstr��
                tmp.push_back(str);
                backtracking(s, endIndex + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};
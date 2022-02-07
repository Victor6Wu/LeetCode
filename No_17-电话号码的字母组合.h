//����һ������������ `2-9` ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� **����˳��** ���ء���ĸ�����ֵ�ӳ�䰴�վż����̡�
#include<vector>
#include<string>
using namespace std;

//���ݷ���digits��ÿ��Ԫ�ظ�����ȡֵ���һ�����ϣ��Լ��Ͻ���ѭ����ѭ���ڽ��еݹ�Ƕ��
class Solution {
private:
    vector<string> result;
    string combine;
    void backtracking(string& s, int Index) {
        if (Index == s.size()) {
            result.push_back(combine);
            return;
        }
        string tmp;
        switch (s[Index]) {
        case '2':
            tmp = "abc";
            break;
        case '3':
            tmp = "def";
            break;
        case '4':
            tmp = "ghi";
            break;
        case '5':
            tmp = "jkl";
            break;
        case '6':
            tmp = "mno";
            break;
        case '7':
            tmp = "pqrs";
            break;
        case '8':
            tmp = "tuv";
            break;
        case '9':
            tmp = "wxyz";
            break;
        }
        for(int i = 0; i < tmp.size(); i++){
            combine.push_back(tmp[i]);
            backtracking(s, Index + 1);
            combine.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtracking(digits, 0);
        return result;
    }
};
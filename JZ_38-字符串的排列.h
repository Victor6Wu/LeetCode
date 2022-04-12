//����һ���ַ�������ӡ�����ַ������ַ����������С�
//�����������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

//���ݷ�����unordered_setʵ��ȥ��
class Solution1 {
private:
    unordered_set<string> ans;
    string tmp;
public:
    void backtrace(string& s, vector<bool>& sign) {
        if (tmp.size() == s.size()) {
            ans.insert(tmp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (sign[i]) continue;
            else {
                tmp.push_back(s[i]);
                sign[i] = true;
                backtrace(s, sign);
                sign[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        vector<bool> sign(s.size(), false);
        backtrace(s, sign);
        return vector<string>(ans.begin(), ans.end());
    }
};

//�ڵݹ麯����ʵ��ȥ�أ��ַ�����Ҫ�Ƚ�������
class Solution2 {
private:
    vector<string> ans;
    string tmp;
public:
    void backtrace(string& s, vector<bool>& sign) {
        if (tmp.size() == s.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            //����ȥ�أ��ǳ��ؼ���һ���ǣ�sign[i - 1] == false�������Ӱ����֦
            if (i > 0 && s[i] == s[i - 1] && sign[i - 1] == false) continue; 
            if (sign[i]) continue;
            else {
                tmp.push_back(s[i]);
                sign[i] = true;
                backtrace(s, sign);
                sign[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());       //��Ϊ����ȥ����Ҫ�õ�ǰ���ַ��ظ��ķ����������Ҫ���ַ�������
        vector<bool> sign(s.size(), false);
        backtrace(s, sign);
        return ans;
    }
};

//���Խ����ֵ���ķ�����������������һ���ֵ�����룬����Ҳ�������ظ�
class Solution {
public:
    bool nextPermutation(string& s) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
        sort(s.begin(), s.end());
        do {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};
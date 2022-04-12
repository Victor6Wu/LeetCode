//����һ���ַ��� s ��һ������ repeatLimit ���� s �е��ַ�����һ�����ַ��� repeatLimitedString ��ʹ�κ���ĸ ���� ���ֵĴ����������� repeatLimit �Ρ��㲻��ʹ�� s �е�ȫ���ַ���
//���� �ֵ������� repeatLimitedString ��
#include<String>
#include<unordered_map>
using namespace std;

//�Ƚ��ַ���s�ṩ�������ַ����մ�z��a��˳��ƴ�ӳ�һ���µ��ַ�����
//�Ų������ظ����ַ�������������������ʱ���ͺͺ����һ�����ظ����ַ����н�����
//��Ҫ�����Ҳ������ظ��ַ���ʱ��Ҫ�������ȫ��ɾ��
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        //ͳ��ÿ���ַ����ֵĴ���
        vector<int> freq(26);
        for (char ch : s) {
            ++freq[ch - 'a'];
        }
        //�������ַ���
        string ans;
        for (int i = 25; i >= 0; i--) {
            for (int j = 1; j <= freq[i]; j++) {
                ans.push_back('a' + i);
            }
        }

        int cnt = 1;    //��¼�ַ��ظ�����
        // ˫ָ��������ַ���
        for (int left = 1, right = 2; left < ans.size(); ++left) {
            if (ans[left - 1] != ans[left]) {
                cnt = 1;
            }
            else {
                ++cnt;
                if (cnt > repeatLimit) {
                    //�������right���м��ɵģ�max(left + 1��right)�ĺô����ڣ�������һ��Ϊ���ҵ����ظ����ַ���right�Ѿ�����ƶ��˺�Զ
                    //��һ�θ��µ�ʱ������ϴλ����ϸ��£����������²���
                    right = max(right, left + 1);       
                                                        
                    while (right < ans.size() && ans[left] == ans[right]) {
                        ++right;
                    }
                    if (right < s.size()) {
                        swap(ans[left], ans[right]);
                        cnt = 1;
                    }
                    else {
                        ans.erase(ans.begin() + left, ans.end());
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
//��������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ�
//��ÿ������ i������һ��θ��ֵ g[i]���������ú���������θ�ڵı��ɵ���С�ߴ磻����ÿ����� j������һ���ߴ� s[j] ��
//��� s[j] >= g[i]�����ǿ��Խ�������� j ��������� i ��������ӻ�õ����㡣
//���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;      //�Ѿ������˵ĺ���
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int ateCookie = -1; //���һ���ù��ı���
        for (int i = 0; i < g.size(); i++) {    //��С�����������
            for (int j = ateCookie + 1; j < s.size(); j++) {    //��С�����Һ��ʵı���
                if (s[j] >= g[i]) {
                    count++;
                    s[j] = -1;
                    ateCookie = j;
                    break;
                }
            }
        }
        return count;
    }
};
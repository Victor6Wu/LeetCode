//����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ��ȡ�
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//̰�ķ������������ַ���һ��ֻ��Сд��ĸ�����Գ�ʼ������Ϊ128������
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int index = 0;
        int maxLen = 0;
        int tmp_len = 0;
        vector<int> vec(128, -1);
        vector<int> loc = vec;
        while (index < n) {
            if (loc[s[index]] == -1) {
                loc[s[index]] = index;
                tmp_len++;
                maxLen = max(maxLen, tmp_len);
                index++;
            }
            else {
                int tmp = loc[s[index]] + 1;
                loc = vec;
                tmp_len = 0;
                index = tmp;
            }
        }
        return maxLen;
    }
};

//�����Ż��������ұ߽��ʾ��������������ÿ�θ�����߽����¿�ʼ��չ�ұ߽�
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int left = 0, right = 0;
        int maxLen = 0;
        vector<int> loc(128, -1);
        for (; right < n; right++) {
            //�ظ����ַ��ڵ�ǰ�Ĵ���
            if (loc[s[right]] >= left) {        
                left = loc[s[right]] + 1;   //������߽�
            }

            loc[s[right]] = right;          //�����ظ��ַ�������λ��
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
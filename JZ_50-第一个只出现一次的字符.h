//��һ����Ϊn���ַ������ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
#include<unordered_map>
#include<string>
using namespace std;

//���ù�ϣ���Ƚ��ַ����ֵĴ���ͳ����������ȥ�����ַ������������������map
class Solution1 {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> table;         //vector<int> table(128, 0);
        for (const char c : str) {
            table[c]++;
        }
        for (int i = 0; i < str.size(); i++) {
            if (table[str[i]] == 1) return i;
        }
        return -1;
    }
};

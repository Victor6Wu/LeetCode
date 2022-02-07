//�ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ��ĸ��������һ��Ƭ���С�
//����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
#include<vector>
#include<string>
using namespace std;

//�Ա����
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int startIndex = 0;
        int endIndex = 0;
        vector<int> result;
        //ͳ�������ַ����һ�γ��ֵ�����/λ��
        vector<int> charIndexs(26, 0);
        for (int i = 0; i < s.size(); i++) {
            int tmp = charIndexs[s[i] - 'a'];
            if (i > tmp) {
                charIndexs[s[i] - 'a'] = i;
            }
        }
        //��ʼ�����ַ�������ѭ����������ұ����䣬�ڹ����и���endIndex
        while (startIndex < s.size()) {
            for (int i = startIndex; i <= endIndex; i++) {
                endIndex = max(endIndex, charIndexs[s[i] - 'a']);
            }
            result.push_back(endIndex - startIndex + 1);
            endIndex++;
            startIndex = endIndex;
        }
        return result;
    }
};

//����Ľ�
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = { 0 }; // iΪ�ַ���hash[i]Ϊ�ַ����ֵ����λ��
        for (int i = 0; i < S.size(); i++) { // ͳ��ÿһ���ַ������ֵ�λ��
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // �ҵ��ַ����ֵ���Զ�߽�
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
//����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��
#include<vector>
#include<string>
using namespace std;

//����1���ڷָ�Ĺ����о�����ÿһ����ֵ��[0,255]֮�䣬���п��ǲ�����0xx���ָ�ʽ
class Solution1 {
private:
    vector<string> result;
    string tmp;
public:
    void backtracking(string& s, int startIndex, int count) {   //startIndex���ڼ�¼��ǰ����㣬count��¼�Ѿ������˼��ε�ַ
        if (count == 4) {
            if (startIndex == s.size()) {           //ֻ��s���պ÷ֳ�4�β�����ЧIP�������ʣ���ַ�û����ָ�����
                result.push_back(tmp);
            }
            return;
        }

        for (int i = 1; startIndex + i <= s.size() && i <= 3; i++) {     //һ���Ϊ3���ַ���i��ʾһ�Σ���seg�ĳ�
            string seg = s.substr(startIndex, i);       //ȡ���Ӷ�
            if (i == 3 && stoi(seg) > 255) {            //�ж��Ƿ񳬳���Χֻ����3λ�����������
                break;
            }

            count += 1;             //����+1
            if (count < 4) {        //�ж��Ƿ�ǰ3��   
                seg += ".";         //���Ķκ����ǲ��ü�'.'��
            }
            tmp += seg;
            backtracking(s, startIndex + i, count);
            //����
            for (int j = 0; j < seg.size(); j++) {
                tmp.pop_back();
            }
            count--;
            //�жϵ�ǰ�ǲ���'0'������ǣ������ѭ���Ͳ���Ҫ��
            if (seg[0] == '0' && i == 1) {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};

//����2���ָ�����п��ܵ���ϣ���������ЧIP�ķ���

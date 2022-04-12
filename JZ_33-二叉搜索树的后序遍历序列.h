//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ��
#include<vector>
using namespace std;

//����ܼ򵥣�Ҫ֪�������������������������ص㣬���ڵ�һ�������ǰ�����������ڵ���������ڵ㹹�ɣ�
//�Ӻ���ǰ�ҵ���һ��С�ڸ��ڵ��ֵ����ô��һ�����������ĸ��ڵ㣬����ȷ�����������ķ�Χ������ͬ���ĵݹ鼴��
//���䣺�ҵ��������ĸ��ڵ����Ҫ����һ���£�������ǰ�������ж��������еĽڵ��ǲ��Ƕ�С�ڵ�ǰ�ĸ��ڵ㣬������Ǿ�ֱ�ӷ���false
class Solution {
public:
    bool core(vector<int>& postorder, int L, int R) {
        if (L >= R) return true;
        int root = postorder[R];
        int gapIndex = R - 1;
        while (gapIndex >= L) {
            if (postorder[gapIndex] < root) break;
            gapIndex--;
        }
        //�жϵ�ǰ���ڵ��Ƿ��������������������С������������
        for (int i = gapIndex - 1; i >= L; i--) {
            if (postorder[i] >= root) return false;
        }

        return core(postorder, L, gapIndex) && core(postorder, gapIndex + 1, R - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return core(postorder, 0, postorder.size() - 1);
    }
};
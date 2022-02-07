//�����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺
//0 <= i, j, k, l < n
//nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
#include<vector>
#include<unordered_map>
using namespace std;

//���η�����ͳ����������͵Ľ�����ٿ�������������ĺ�
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;       //��¼��������͵Ľ�����ֵĴ���
        for (int a : nums1) {   
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;                      //���ڼ�¼������Ŀ�����ĸ���
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};
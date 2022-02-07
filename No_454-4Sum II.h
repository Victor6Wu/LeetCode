//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
//0 <= i, j, k, l < n
//nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
#include<vector>
#include<unordered_map>
using namespace std;

//分治法，先统计两个数组和的结果，再看另外两个数组的和
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;       //记录两个数组和的结果出现的次数
        for (int a : nums1) {   
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;                      //用于记录满足题目条件的个数
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
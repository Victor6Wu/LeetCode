//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������
#include<vector>
using namespace std;

//�鲢����
//����Ľ�����ڹ鲢����Ĺ������ۼƵó��ģ�����ҪŪ����鲢�Ĺ������¼����ԵĹ�ϵ��
//������ֳ�������������A��B���ֱ�ʵ���˵������ص㣬�ڹ鲢AB�Ĺ����У��Ҳ��B������Ԫ�ر�A�е�С����ô�͡�������A��ʣ��Ԫ��������ȵ������������
//���Ѿ��鲢��ɵ������ڲ�����������Ѿ�ͳ����ϣ�������һ��鲢��ʱ���Ѿ����迼���ڲ���Ԫ��˳��ֻ��Ҫ�ظ���һ���Ĺ�������
class Solution {
public:
    void merge(vector<int>& nums, vector<int>& tmp, int L, int R, int& count) {
        if (L >= R) return;
        int mid = L + (R - L) / 2;
        merge(nums, tmp, L, mid, count);
        merge(nums, tmp, mid + 1, R, count);
        int index = L, p1 = L, p2 = mid + 1;
        while (p1 <= mid && p2 <= R) {
            if (nums[p1] <= nums[p2]) tmp[index++] = nums[p1++];
            else {
                tmp[index++] = nums[p2++];
                count += (mid - p1 + 1);        //ֻ���Ҳ������е���������������С��ʱ��ͳ��
            }
        }
        while (p1 <= mid) tmp[index++] = nums[p1++];
        while (p2 <= R) tmp[index++] = nums[p2++];

        for (int i = L; i <= R; i++) {
            nums[i] = tmp[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        vector<int> tmp(nums.size(), 0);
        merge(nums, tmp, 0, nums.size() - 1, count);
        return count;
    }
};
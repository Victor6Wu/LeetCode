//����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
//�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
#include<vector>
using namespace std;

//ע�����⣬������Ǻ�Ϊtarget�ġ����������������У����ٰ���2����
//���������� 1 �� target/2 ������Ϊ��ʼֵ�������ۼӲ���������͵���target�ͱ��棬������������һ����ʼֵ
//ʱ�临�Ӷ�O(target��sqrt(target))
class Solution1 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 ��Ч�� target / 2 ��ȡ��
        for (int i = 1; i <= limit; ++i) {
            for (int j = i; j < target; ++j) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                }
                else if (sum == target) {
                    res.clear();
                    //��i��ʼ��j�����ִ洢
                    for (int k = i; k <= j; ++k) {
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};

//�������Ż���֮ǰ��i�𣬵�jֹ��ͨ�������ķ�ʽ����ģ���ʵ���ۼƺ����й�ʽ��ѭ�ģ�����һԪ���η������޽��һ���ó�j����
//ʱ�临�Ӷ�O(target)
class Solution2 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 ��Ч�� target / 2 ��ȡ��
        for (int x = 1; x <= limit; ++x) {
            long long delta = 1 - 4 * (x - 1ll * x * x - 2 * target);
            if (delta < 0) {
                continue;
            }
            int delta_sqrt = (int)sqrt(delta + 0.5);
            if (1ll * delta_sqrt * delta_sqrt == delta && (delta_sqrt - 1) % 2 == 0) {
                int y = (-1 + delta_sqrt) / 2; // ��һ����(-1-delta_sqrt)/2��ȻС��0�����ÿ���
                if (x < y) {
                    res.clear();
                    for (int i = x; i <= y; ++i) {
                        res.emplace_back(i);
                    }
                    vec.emplace_back(res);
                }
            }
        }
        return vec;
    }
};

//˫ָ�뷨����ʵ˼·Ҳ�������ڷ���1���Ż����Ѿ�ö�ٵĲ��֣��������ظ�����
//ע��ѭ������ֹ����
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target <= 2) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        int left = 1, right = 2;
        while (left < right) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                tmp.clear();
                for (int i = left; i <= right; i++) {
                    tmp.push_back(i);
                }
                ans.push_back(tmp);
                left++;         //�˴�left++һ���������ǣ����������ѭ��
            }
            else if (sum < target) right++;
            else left++;
        }
        return ans;
    }
};
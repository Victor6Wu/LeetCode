//�����������飬��дһ���������������ǵĽ�����
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//����1����setд
class Solution1 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> tmp;			//��Ž�����������ظ���ֵ
		unordered_set<int> table(nums1.begin(), nums1.end());
		for (int it : nums2) {
			if (table.find(it) != table.end()) {
				tmp.insert(it);
			}
		}
		return vector<int>(tmp.begin(), tmp.end());
	}
};


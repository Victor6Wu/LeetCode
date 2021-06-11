//Given two strings s and t of lengths m and n respectively, 
//return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
//If there is no such substring, return the empty string "".
//The testcases will be generated such that the answer is unique.
//A substring is a contiguous sequence of characters within the string.
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	//solution 1:�Ա���룬��Щ����޷����㣬������
	//string minWindow(string s, string t) {
	//	//����һ���������ڴ��t�г��ֵ���ĸ����
	//	int map_t[128];
	//	for (int i = 0; i < 128; i++) {
	//		map_t[i] = -1;
	//	}

	//	for (int i = 0; i < t.size(); ++i) {
	//		char c = t[i];
	//		map_t[(int)c] = 0;
	//	}

	//	for (int i = 0; i < t.size(); ++i) {
	//		char c = t[i];
	//		map_t[(int)c]++;
	//	}

	//	//���ҵ��������ĵ�һ����߽�
	//	int left_ptr = 0, len_s = s.size();
	//	for (; left_ptr < len_s; ++left_ptr) {
	//		if (map_t[s[left_ptr]] != false) break;
	//	}
	//	int right_ptr = left_ptr;

	//	//����map�洢�Ѿ��ҵ����ַ�,key��ʾ������value��ʾ�ַ�
	//	string str = s;
	//	bool signal = false;
	//	map<int, char> map_s;
	//	for (; right_ptr < len_s; ++right_ptr) {
	//		if (map_t[s[right_ptr]] != -1) {
	//			if (map_t[s[right_ptr]] > 0) {
	//				--map_t[s[right_ptr]];
	//				map_s[right_ptr] = s[right_ptr];
	//				continue;
	//			}
	//			//������Ҫ������߽�����
	//			if (map_t[s[right_ptr]] == 0) {
	//				//�����ʱ�պ�ƥ�䣬��Ҫȡ����ʱ���ڱ�ʾ���Ӵ�
	//				if (map_s.size() == t.size()) {
	//					auto left_it = map_s.begin();
	//					auto right_it = map_s.end();
	//					right_it--;
	//					int len_str = right_it->first - left_it->first + 1;    //��Ҫ+1����Ϊ�����������߽��Ԫ��
	//					if (len_str <= str.size()) {
	//						str = s.substr(left_it->first, len_str);
	//						signal = true;
	//					}
	//					//������߽�
	//					auto it = map_s.begin();
	//					map_s.erase(it);
	//					left_ptr = map_s.begin()->first;
	//				}
	//				//��Ҫ����s���������ַ����������s="aaaabbbcdd"��t="abcdd"
	//				if ( map_s.size() >= 2 && (s[right_ptr] == s[right_ptr - 1])) {
	//					map_s.erase(right_ptr - 1);
	//					map_s[right_ptr] = s[right_ptr];
	//					continue;
	//				}

	//				//������߽總����һϵ�в������ͷ�map_s���µ���߽�����Ԫ�أ�ͬ������map_t�еĸ���
	//				auto it = map_s.begin();
	//				while (it != map_s.end()) {
	//					//ѭ������
	//					if (it->second != s[right_ptr]) {
	//						map_t[it->second]++;		//����map_t�ж�Ӧ�ַ��ĸ���
	//						map_s.erase(it);			//�ͷ�map_s���±߽�����Ԫ��
	//						it = map_s.begin();
	//					}
	//					//�ҵ���ӦԪ�غ�ֻ��Ҫ������߽磬ͬʱ�޸ĸ�Ԫ����map_s�еļ�
	//					if (it->second == s[right_ptr]) {
	//						map_s.erase(it);
	//						map_s[right_ptr] = s[right_ptr];		//�޸ĸ�Ԫ����map_s�еļ�
	//						//�������ֱ�ʾ�����ǳ��ã������˿���map_s���Ƿ����һ��Ԫ�ص����
	//						left_ptr = map_s.begin()->first;		//���»���������߽�
	//						break;
	//					}
	//				}
	//					
	//			}
	//		}
	//	}

	//	//ѭ����������Ҫ���map_s����ֹ��©sβ������������Ŀ�������Ӵ�
	//	if (map_s.size() == t.size()) {
	//		auto left_it = map_s.begin();
	//		auto right_it = map_s.end();
	//		right_it--;
	//		int len_str = right_it->first - left_it->first + 1;    //��Ҫ+1����Ϊ�����������߽��Ԫ��
	//		if (len_str <= str.size()) {
	//			str = s.substr(left_it->first, len_str);
	//			signal = true;
	//		}
	//	}
	//	if(signal) return str;
	//	return "";
	//}

	
	/*
	* //solution 1:��������,����map
	unordered_map<char, int> map_t, map_s;
	//������鸲�����ĺ���
	bool check() {
		for (const auto& p : map_t) {
			if (map_s[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c : t) {
			++map_t[c];
		}

		int left = 0, right = -1;
		int len = INT_MAX, temp_left = -1;		//temp_left���˿��Դ洢�Ӵ�����㣬Ҳ�൱��һ��signal�������Ƿ����������Ŀ�������ִ�

		while (right < int(s.size())) {			//�˴�s.size()Ҫת��int���ͣ��䱾�����޷�����������-1�޷��Ƚ�
			if (map_t.find(s[++right]) != map_t.end()) {
				++map_s[s[right]];
			}
			while (check() && left <= right) {
				//���ƻ���������߽�֮ǰ�������ʱ���Ӵ�
				if (right - left + 1 < len) {
					len = right - left + 1;		//�洢��ʱ�������Ĵ���
					temp_left = left;			//�洢��ʱ����������߽�
				}
				//���ƻ���������߽�
				if (map_t.find(s[left]) != map_t.end()) {//�жϴ�ʱ��߽���ַ���t�����
					--map_s[s[left]];	//��1�����ٵ���0����Ϊ��߽����ƽ�Ҫɨ����λ�ö����ұ߽��Ѿ�ɨ����λ��
				}
				++left;
			}
		}
		//���������������Ӵ�
		return temp_left == -1 ? "" : s.substr(temp_left, len);
	}*/

	//solution 2:��������,�����������map
	int map_t[128], map_s[128];
	//������鸲�����ĺ���
	bool check() {
		for (int i = 0; i < 128;++i) {
			if (map_s[i] < map_t[i]) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c : t) {
			++map_t[c];
		}

		int left = 0, right = -1;
		int len = INT_MAX, temp_left = -1;		//temp_left���˿��Դ洢�Ӵ�����㣬Ҳ�൱��һ��signal�������Ƿ����������Ŀ�������ִ�

		while (right < int(s.size())) {			//�˴�s.size()Ҫת��int���ͣ��䱾�����޷�����������-1�޷��Ƚ�
			if (map_t[s[++right]] != 0) {
				++map_s[s[right]];
			}
			while (check() && left <= right) {
				//���ƻ���������߽�֮ǰ�������ʱ���Ӵ�
				if (right - left + 1 < len) {
					len = right - left + 1;		//�洢��ʱ�������Ĵ���
					temp_left = left;			//�洢��ʱ����������߽�
				}
				//���ƻ���������߽�
				if (map_t[s[left]] != 0) {//�жϴ�ʱ��߽���ַ���t�����
					--map_s[s[left]];	//��1�����ٵ���0����Ϊ��߽����ƽ�Ҫɨ����λ�ö����ұ߽��Ѿ�ɨ����λ��
				}
				++left;
			}
		}
		//���������������Ӵ�
		return temp_left == -1 ? "" : s.substr(temp_left, len);
	}
};

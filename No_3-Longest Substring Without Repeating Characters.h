//Given a string s, find the length of the longest substring without repeating characters.
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
	public:
		//solution 1: set�����򼯺ϣ����ǣ��������˳�����������򣬲��ǲ���Ԫ�ص�˳��������δ��벻����ʵ���ˣ�
		/*int lengthOfLongestSubstring(string s) {
			set<char> container;
			int n = s.length();
			int result_length = 0, begin = 0;
			while (begin < n) {
				if (container.empty() || (container.find(s[begin]) == container.end())) {
					container.insert(s[begin++]);
					if (begin == n) result_length = max(result_length, int(container.size()));
				}
				else {
					result_length = max(result_length,int(container.size()));
					//ȷ���ظ�Ԫ�ص�λ��
					auto iter = container.find(s[begin]);
					int position = -1;
					while (iter != container.end()) {
						position++;
						iter++;
					}
					begin = begin - position;
					container = set<char>();
				}
			}
			return result_length;
		}*/

		//solution 1: set�����򼯺ϣ����ǣ��������˳�������ݵ�˳�򣬲��ǲ���Ԫ�ص�˳��������δ��벻����ʵ���ˣ�����vector
		int lengthOfLongestSubstring1(string s) {
			vector<char> container;
			int n = s.length();
			int result_length = 0, begin = 0;
			while (begin < n) {
				if (container.empty() || (find(container.begin(),container.end(),s[begin]) == container.end())) {
					container.push_back(s[begin++]);
					if (begin == n) result_length = max(result_length, int(container.size()));	//ֻ�н���ǰ��Ӧ���Ӵ��Ż�����޷�����else�����ִ����ȵ����
				}
				else {
					result_length = max(result_length, int(container.size()));				//�����ظ��ַ�Ϊ��־�����µ�ǰ������Ӵ�����

					//ȷ���ظ�Ԫ�ص�λ��
					auto iter = find(container.begin(), container.end(), s[begin]);
					int position = -1;
					while (iter != container.end()) {
						position++;
						iter++;
					}

					begin = begin - position;					//ʹ�ȸ���Ϊ�ظ��ַ�֮���λ�ã�����������
					container = vector<char>();					//����Ҫ���
				}
			}
			return result_length;
		}

		//solution 2: ��solution 1 ˼·�������ƣ�ֻ�ǲ���unordered_map���ڴ洢���ظ����ִ��������ڲ����ʱ��Ԫ�ص���Ҳ���룬�����ҵ��µ���ʼλ
		int lengthOfLongestSubstring2(string s) {
			unordered_map<char,int> table;
			int n = s.length();
			int	ans = 0, index = 0;
			while(index < n) {
				auto it = table.find(s[index]);
				if (it == table.end()) {
					table[s[index]] = index;
					++index;
					if (index == n) return max(ans, int(table.size()));		//����Ҫ����仰������һֱû�г����ظ�
				}															//��һֱû�и���ans
				else {
					ans = max(ans, int(table.size()));
					index = it->second + 1;
					table.clear();
				}
			}
			return ans;
		}
		//solution 3�� ����������Ҳ������˼·������������˫ָ�룬����򵥱�ݣ�Ч�ʸ��ߣ�������߽������ö��
		//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(�ַ���)
		int lengthOfLongestSubstring3(string s) {
			// ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
			unordered_set<char> char_table;
			int n = s.size();
			// ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
			int right_ptr = -1, ans = 0;
			// ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
			for (int i = 0; i < n; ++i) {
				if (i != 0) {
					// ��ָ�������ƶ�һ���Ƴ�һ���ַ�
					char_table.erase(s[i - 1]);
				}
				while (right_ptr + 1 < n && !char_table.count(s[right_ptr + 1])) {
					// ���ϵ��ƶ���ָ��
					char_table.insert(s[right_ptr + 1]);
					++right_ptr;
				}
				// �� i �� right_ptr ���ַ���һ�����������ظ��ַ��Ӵ�
				ans = max(ans, right_ptr - i + 1);
			}
			return ans;
		}

		//solution 4: ��solution 3�Ļ�����������ͬ��ͬ����Ҫ������߽�
		int lengthOfLongestSubstring4(string s) {
			int n = s.length();
			if (n == 0) return 0;
			unordered_map<char, int> char_table;
			int maxLength = 0;
			int currentLength = 0;
			int startIndex = 0;

			for (int i = 0; i < n; ++i) {
				if (char_table.find(s[i]) == char_table.end()) {
					currentLength++;
					char_table[s[i]] = i;
				}
				else {
					if (currentLength > maxLength) {
						maxLength = currentLength;
					}
					//�������ظ��ַ�ʱ���ҵ����ظ����ַ�������startIndex�͵�ǰ�����Լ� ��ϣ���д��ַ�������
					startIndex = max(char_table[s[i]], startIndex);
					currentLength = i - startIndex;
					char_table[s[i]] = i;
				}
			}
			//���ڷ�ֹ�ַ�������������һ�����������ظ��ִ�����solution 1��2 ���ж�index==n ����һ��
			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
			return maxLength;
		}

		//solution 5�������Ļ��ƴ�����ö�����е���߽磬ֻ�����λ�úͺ�����ֵ������ظ��ַ��ĺ�һλ��Ϊ��߽磬��������ʵ�ֹ�ϣ�������
		//ֻ���ҵ�һ���ظ��ַ���Ҫ�Ƚ�����jֵ�Ĵ�С
		int lengthOfLongestSubstring5(string s) {
			int map[128];
			int max_len = 0;
			int j = -1;
			int i;
			//ÿ�������ʼ��Ϊ-1
			for (i = 0; i < 128; i++) {
				map[i] = -1;
			}
			for (i = 0; i < s.size(); i++) {
				char c = s[i];
				//�ҵ��ظ��ַ�
				if (map[(int)c] != -1) {

					//�ǳ��ؼ���һ���������δ��룺һ���ظ���i�������ƣ����ҵ�һ���ظ��ַ����жϸ��ַ���Ӧ���ظ��ַ��������Ƿ����ϴ��ظ����ַ�����֮ǰ
					//������ϴ��ظ��ַ�������֮ǰ����û�б�Ҫͳ����֮����Ӵ�����Ϊ���м��Ȼ�������ϴ��ظ��ַ�Ϊ��β���ִ�
					//ֻ��Ҫ���¸��ַ�������ֵ
					if (map[(int)c] < j) {
						map[(int)c] = i;
						continue;
					}

					//������ϴ��ظ��ַ�������֮���൱�ڴ��ϴε�jֵ��ʼ���µ��Ӵ�
					max_len = max(max_len, i - (j + 1));
					j = map[(int)c];
					map[(int)c] = i;
				}
				//δ�ҵ��ظ��ַ������޸������Ӧλ�õ���ֵ
				else {
					map[(int)c] = i;
				}
			}
			max_len = max(max_len, i - (j + 1));
			return max_len;
		}
};
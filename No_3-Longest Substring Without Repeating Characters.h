//Given a string s, find the length of the longest substring without repeating characters.
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
	public:
		//solution 1: set是有序集合，但是！！！这个顺序是内容排序，不是插入元素的顺序，所以这段代码不可能实现了！
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
					//确定重复元素的位置
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

		//solution 1: set是有序集合，但是！！！这个顺序是内容的顺序，不是插入元素的顺序，所以这段代码不可能实现了！改用vector
		int lengthOfLongestSubstring1(string s) {
			vector<char> container;
			int n = s.length();
			int result_length = 0, begin = 0;
			while (begin < n) {
				if (container.empty() || (find(container.begin(),container.end(),s[begin]) == container.end())) {
					container.push_back(s[begin++]);
					if (begin == n) result_length = max(result_length, int(container.size()));	//只有结束前对应的子串才会出现无法进入else计算字串长度的情况
				}
				else {
					result_length = max(result_length, int(container.size()));				//遇到重复字符为标志，更新当前的最大子串长度

					//确定重复元素的位置
					auto iter = find(container.begin(), container.end(), s[begin]);
					int position = -1;
					while (iter != container.end()) {
						position++;
						iter++;
					}

					begin = begin - position;					//使秩更新为重复字符之后的位置，继续向后查找
					container = vector<char>();					//容器要清空
				}
			}
			return result_length;
		}

		//solution 2: 与solution 1 思路基本类似，只是采用unordered_map用于存储不重复的字串，这样在插入的时候将元素的秩也插入，方便找到新的起始位
		int lengthOfLongestSubstring2(string s) {
			unordered_map<char,int> table;
			int n = s.length();
			int	ans = 0, index = 0;
			while(index < n) {
				auto it = table.find(s[index]);
				if (it == table.end()) {
					table[s[index]] = index;
					++index;
					if (index == n) return max(ans, int(table.size()));		//必须要有这句话，否则一直没有出现重复
				}															//就一直没有更新ans
				else {
					ans = max(ans, int(table.size()));
					index = it->second + 1;
					table.clear();
				}
			}
			return ans;
		}
		//solution 3： 滑动窗法，也是类似思路，但是利用了双指针，代码简单便捷，效率更高，尽管左边界是逐个枚举
		//时间复杂度O(n)，空间复杂度O(字符集)
		int lengthOfLongestSubstring3(string s) {
			// 哈希集合，记录每个字符是否出现过
			unordered_set<char> char_table;
			int n = s.size();
			// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
			int right_ptr = -1, ans = 0;
			// 枚举左指针的位置，初始值隐性地表示为 -1
			for (int i = 0; i < n; ++i) {
				if (i != 0) {
					// 左指针向右移动一格，移除一个字符
					char_table.erase(s[i - 1]);
				}
				while (right_ptr + 1 < n && !char_table.count(s[right_ptr + 1])) {
					// 不断地移动右指针
					char_table.insert(s[right_ptr + 1]);
					++right_ptr;
				}
				// 第 i 到 right_ptr 个字符是一个极长的无重复字符子串
				ans = max(ans, right_ptr - i + 1);
			}
			return ans;
		}

		//solution 4: 与solution 3的滑动窗方法相同，同样需要遍历左边界
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
					//当遇到重复字符时，找到被重复的字符，更新startIndex和当前长度以及 哈希表中此字符的索引
					startIndex = max(char_table[s[i]], startIndex);
					currentLength = i - startIndex;
					char_table[s[i]] = i;
				}
			}
			//用于防止字符串的最后出现了一段连续的无重复字串，与solution 1和2 中判断index==n 功能一样
			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
			return maxLength;
		}

		//solution 5：真正的滑移窗，不枚举所有的左边界，只有最初位置和后面出现的所有重复字符的后一位作为左边界，利用数组实现哈希表的作用
		//只是找到一个重复字符后要比较其与j值的大小
		int lengthOfLongestSubstring5(string s) {
			int map[128];
			int max_len = 0;
			int j = -1;
			int i;
			//每个数组初始化为-1
			for (i = 0; i < 128; i++) {
				map[i] = -1;
			}
			for (i = 0; i < s.size(); i++) {
				char c = s[i];
				//找到重复字符
				if (map[(int)c] != -1) {

					//非常关键的一点就在于这段代码：一次重复后，i继续后移，再找到一个重复字符，判断该字符对应的重复字符的索引是否在上次重复的字符索引之前
					//如果在上次重复字符的索引之前，则没有必要统计这之间的子串，因为这中间必然包含了上次重复字符为首尾的字串
					//只需要更新该字符的索引值
					if (map[(int)c] < j) {
						map[(int)c] = i;
						continue;
					}

					//如果在上次重复字符的索引之后，相当于从上次的j值开始的新的子串
					max_len = max(max_len, i - (j + 1));
					j = map[(int)c];
					map[(int)c] = i;
				}
				//未找到重复字符，就修改数组对应位置的数值
				else {
					map[(int)c] = i;
				}
			}
			max_len = max(max_len, i - (j + 1));
			return max_len;
		}
};
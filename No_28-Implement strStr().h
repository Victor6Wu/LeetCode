//Implement strStr().
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include<string>
using namespace std;

class Solution {
public:
	//solution 1:±©¡¶∆•≈‰
	int strStr(string haystack, string needle) {
		int len_haystack = haystack.size(), len_needle = needle.size();
		if (len_needle == 0) return 0;
		int i = 0;
		while ((i + len_needle - 1) < len_haystack) {
			string str = haystack.substr(i, len_needle);
			if (str == needle) return i;
			++i;
		}
		return -1;
	}
};

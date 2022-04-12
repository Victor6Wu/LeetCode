#include<string>
using namespace std;

int getCount(string mainStr, string subStr) {
    int i = mainStr.length(), j = subStr.length();
    int count = 0;
    if (i >= j) {
        int pos = 0;
        int k = mainStr.find(subStr, pos);
        while (k != mainStr.npos) {
            count++;
            pos = k + j;
            k = mainStr.find(subStr, pos);
        }
    }
    return count;
}
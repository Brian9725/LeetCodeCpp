#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size(), result = 0, idx = -1;
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				idx = i;
				break;
			}
		}
		for (int i = idx - 1; i >= 0; i--) {
			if (s[i] == ' ') {
				return idx - i;
			}
		}
		result = idx + 1;
		return result;
	}
};
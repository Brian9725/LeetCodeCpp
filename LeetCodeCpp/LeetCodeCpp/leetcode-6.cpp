#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) 
			return s;
		int len = s.size(), cnt = 0;
		string result = "";
		for (int i = 0; i < numRows; i++) {
			//如果是Z字的头和尾，则每个元素之间间隔的元素个数是一样的
			if (i == 0 || i == numRows - 1) {
				for (int j = i; j < len; j += 2 * numRows - 2) 
					result += s[j];
				continue;
			}
			//如果不是Z的头尾，则每个元素之间的间隔在两个数之间不断转变
			int  num = 2 * i;
			for (int j = i; j < len; j += num) {
				result += s[j];
				num = 2 * numRows - 2 - num;
			}
		}
		return result;
	}
};
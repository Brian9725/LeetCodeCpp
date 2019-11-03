#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int result = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			//必须先-'A'，如果先+s[i]，部分编译器会在result*26+s[i]时溢出
			result = result * 26 - 'A' + s[i] + 1;
		}
		return result;
	}
};
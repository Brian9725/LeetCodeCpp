#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int result = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			//������-'A'�������+s[i]�����ֱ���������result*26+s[i]ʱ���
			result = result * 26 - 'A' + s[i] + 1;
		}
		return result;
	}
};
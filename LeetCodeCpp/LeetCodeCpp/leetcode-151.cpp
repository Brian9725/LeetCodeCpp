#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int len = s.size(), idx = 0;
		string res = "";
		while (idx < len) {
			if (s[idx] == ' ') {
				idx++; continue;
			}
			int tempLen = 0;
			while (idx + tempLen < len && s[idx + tempLen] != ' ') {
				tempLen++;
			}
			string tempStr = s.substr(idx, tempLen);
			res = tempStr + " " + res;
			idx += tempLen;
		}
		//去掉结尾的空格
		res = res.substr(0, res.size() - 1);
		return res;
	}
};
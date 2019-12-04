#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int balancedStringSplit(string s) {
		int res = 0, cnt = 0, len = s.size();
		for (int i = 0; i < len; ++i) {
			if (s[i] == 'L') cnt++;
			if (s[i] == 'R') cnt--;
			if (cnt == 0) res++;
		}
		return res;
	}
};
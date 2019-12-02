#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, int> sMap, tMap;
		int len = s.size(), cntS = 0, cntT = 0;
		for (int i = 0; i < len; ++i) {
			if (sMap.find(s[i]) == sMap.end()) sMap[s[i]] = cntS++;
			if (tMap.find(t[i]) == tMap.end()) tMap[t[i]] = cntT++;
			if (sMap[s[i]] != tMap[t[i]]) return false;
		}
		return true;
	}
};
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		if (lenS != lenT) return false;
		int letter[26] = { 0 };
		for (int i = 0; i < lenS; ++i) {
			letter[s[i] - 'a']++;
			letter[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; ++i) {
			if (letter[i] != 0) return false;
		}
		return true;
	}
};
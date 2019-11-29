#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int len = s.size();
		int letter[26] = { 0 };
		for (int i = 0; i < len; ++i) {
			letter[s[i] - 'a']--;
			letter[t[i] - 'a']++;
		}
		letter[t[len] - 'a']++;
		for (int i = 0; i < 26; ++i) {
			if (letter[i] == 1) return 'a' + i;
		}
		return 'a';
	}
};
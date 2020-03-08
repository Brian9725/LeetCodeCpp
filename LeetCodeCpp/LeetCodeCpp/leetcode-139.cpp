#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size(), wordLen = wordDict.size();
		if (len == 0) return true;
		if (wordLen == 0) return false;
		int *dp = new int[len + 1]; dp[0] = 1;
		for (int i = 1; i <= len; ++i) { dp[i] = 0; }
		for (int i = 1; i <= len; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				string str = s.substr(j, i - j);
				if (dp[j] == 0) continue;
				if (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = 1;
				}
			}
		}
		return dp[len];
	}
};
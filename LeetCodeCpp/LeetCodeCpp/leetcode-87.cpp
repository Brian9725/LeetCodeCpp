#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) 
			return false;
		if (s1.empty()) 
			return true;
		int N = s1.size();
		//dp[len][i][j]表示s1[i,i+len]和s2[j,j+len]是否是扰乱字符串
		vector<vector<vector<bool> > > dp(N + 1, vector<vector<bool> >(N, vector<bool>(N, false)));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dp[1][i][j] = s1[i] == s2[j];
			}
		}
		for (int len = 2; len <= N; ++len) {
			for (int i = 0; i < N && i + len - 1 < N; ++i) {
				for (int j = 0; j < N && j + len - 1 < N; ++j) {
					for (int k = 1; k < len; ++k) {
						if (dp[k][i][j] && dp[len - k][i + k][j + k]) {
							dp[len][i][j] = true; break;
						}
						if (dp[k][i][j + len - k] && dp[len - k][i + k][j]) {
							dp[len][i][j] = true; break;
						}
					}
				}
			}
		}
		return dp[N][0][0];
	}

	/*递归
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int len1 = s1.size(), len2 = s2.size();
		if (len1 != len2)
			return false;
		//判断s1和s2中出现的各个字符数量是否一样
		int letters[26] = { 0 };
		for (int i = 0; i < len1; i++) {
			letters[s1[i] - 'a']++;
			letters[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (letters[i] != 0)
				return false;
		}
		for (int i = 1; i < len1; i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len2 - i)) && isScramble(s1.substr(i), s2.substr(0, len2 - i)))
				return true;
		}
		return false;
	}
	*/
};
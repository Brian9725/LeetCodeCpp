#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int lenS = s.size(), lenP = p.size(), temp = 0;
		//dp[i][j]表示p的前i个字符能否匹配s的前j个字符
		vector<vector<int>> dp(lenP + 1, vector<int>(lenS + 1, 0)); 
		//初始化dp数组
		dp[0][0] = 1;
		for (int i = 2; i <= lenP; i++) {
			if (dp[i - 2][0] == 1 && p[i - 1] == '*')
				dp[i][0] = 1;
		}
		for (int i = 1; i <= lenP; i++) {
			for (int j = 1; j <= lenS; j++) {
				if (p[i - 1] == '*') {
					if (dp[i - 1][j] == 1 || dp[i - 2][j] == 1 ||
						(dp[i][j - 1] == 1 && (p[i - 2] == '.' || p[i - 2] == s[j - 1])))
						dp[i][j] = 1;
				}
				else if (p[i - 1] == '.') {
					if (dp[i - 1][j - 1] == 1)
						dp[i][j] = 1;
				}
				else {
					if (dp[i - 1][j - 1] == 1 && p[i - 1] == s[j - 1])
						dp[i][j] = 1;
				}
			}
		}
		return dp[lenP][lenS] == 1;
	}
};
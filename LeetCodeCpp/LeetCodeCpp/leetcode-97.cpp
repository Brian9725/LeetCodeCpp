#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
		if (len1 + len2 != len3)
			return false;
		if (len1 == 0)
			return s2 == s3;
		if (len2 == 0)
			return s1 == s3;
		//dp[i][j]表示s1的前i个字符和s2的前j个字符能付交错构成s3的前i+j个字符
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= len1; i++) {
			if (dp[i - 1][0] == 1 && s1[i - 1] == s3[i - 1])
				dp[i][0] = 1;
		}
		for (int i = 1; i <= len2; i++) {
			if (dp[0][i - 1] == 1 && s2[i - 1] == s3[i - 1])
				dp[0][i] = 1;
		}
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				if ((dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]) ||
					dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1])
					dp[i][j] = 1;
			}
		}
		return dp[len1][len2] == 1;
	}
};
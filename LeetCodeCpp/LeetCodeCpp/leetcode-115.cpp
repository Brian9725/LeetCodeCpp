#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		if (lenS == 0 && lenT == 0)
			return 1;
		if (lenS == 0 || lenT == 0 || lenS < lenT)
			return 0;
		//虽然最后的结果不会超出int范围，但是中间结果会超出int范围
		//dp[i][j]表示t中前i个字符与s中前j个字符匹配的结果数
		vector<vector<long long>> dp(lenT + 1, vector<long long>(lenS + 1, 0));
		for (int i = 0; i <= lenT; i++) {
			for (int j = 0; j <= lenS; j++) {
				if (i == 0) {
					dp[i][j] = 1; continue;
				}
				if (j == 0) {
					dp[i][j] = 0; continue;
				}
				//如果t中第i个字符与s中第j个字符不等，dp[i][j]=dp[i][j-1]
				//如果相等，dp[i][j]=dp[i][j-1]+dp[i-1][j-1]
				dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
			}
		}
		return dp[lenT][lenS];
	}
};
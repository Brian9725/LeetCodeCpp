#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//可优化至常量空间
	int numDecodings(string s) {
		int len = s.size();
		vector<int> dp(len + 1, 0);
		dp[0] = 1; dp[1] = (s[0] == '0') ? 0 : 1;
		for (int i = 2; i <= len; i++) {
			if (s[i - 1] >= '1' && s[i - 1] <= '9')
				dp[i] += dp[i - 1];
			if ((s[i - 2] == '1' && s[i - 1] >= '0' && s[i - 1] <= '9') ||
				(s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6'))
				dp[i] += dp[i - 2];
		}
		return dp[len];
	}
};
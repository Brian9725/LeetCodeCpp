#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int days = prices.size();
		if (days < 2)
			return 0;
		//dp定义参见leetcode-123（或其题解）
		vector<vector<int>> dp(days + 1, vector<int>(2, 0));
		dp[0][1] = INT_MIN;
		for (int i = 1; i <= days; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1] - fee);
		}
		return dp[days][0];
	}
};
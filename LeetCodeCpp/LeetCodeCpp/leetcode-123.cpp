#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//leetcode-123题解为通用方法
	int maxProfit(vector<int>& prices) {
		int days = prices.size();
		//dp[i][k][j]表示第i天进行了k次交易，j为0表示不持有股票，为1表示持有股票
		//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
		//dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
		vector<vector<vector<int>>> dp(days + 1, vector<vector<int>>(3, vector<int>(2, 0)));
		for (int i = 0; i <= 2; i++) {
			dp[0][i][1] = INT_MIN;
		}
		for (int i = 1; i <= days; i++) {
			dp[i][0][1] = INT_MIN;
			for (int k = 1; k <= 2; k++) {
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i - 1]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i - 1]);
			}
		}
		return dp[days][2][0];
	}
};
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//将leetcode-123推广并优化空间复杂度
	int maxProfit(int k, vector<int>& prices) {
		int days = prices.size();
		if (days < 2 || k < 1)
			return 0;
		//完成一次交易至少要两天，所以当k大于天数的一半时，可以视作可交易任意次数
		if (k >= days / 2) {
			//此部分代码为leetcode-122
			int result = 0;
			for (int i = 1; i < days; i++) {
				if (prices[i] - prices[i - 1] > 0)
					result += prices[i] - prices[i - 1];
			}
			return result;
		}
		vector<vector<int>> dp(k + 1, vector<int>(2, 0));
		for (int i = 0; i <= k; i++) {
			dp[i][1] = INT_MIN;
		}
		for (int i = 1; i <= days; i++) {
			//计算dp[i][k][1]时需要用到dp[i-1][j-1][0]，将dp优化成二维后dp[i-1][j-1][0]会被覆盖，所以用temp记录下来
			//dp的定义参见leetcode-123
			int temp = dp[0][0];
			for (int j = 1; j <= k; j++) {
				dp[j][0] = max(dp[j][0], dp[j][1] + prices[i - 1]);
				dp[j][1] = max(dp[j][1], temp - prices[i - 1]);
				temp = dp[j][0];
			}
		}
		return dp[k][0];
	}
};
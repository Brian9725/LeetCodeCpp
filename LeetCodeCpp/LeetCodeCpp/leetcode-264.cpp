#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n, 1);
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; ++i) {
			int temp = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
			if (temp == dp[p2] * 2) p2++;
			if (temp == dp[p3] * 3) p3++;
			if (temp == dp[p5] * 5) p5++;
			dp[i] = temp;
		}
		return dp[n - 1];
	}
};
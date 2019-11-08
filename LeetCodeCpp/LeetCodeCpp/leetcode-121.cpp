#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1)
			return 0;
		int maxProfit = 0, min = prices[0];
		for (int i = 1; i < len; i++) {
			if (prices[i] <= min) {
				min = prices[i];
				continue;
			}
			else {
				if (maxProfit < prices[i] - min)
					maxProfit = prices[i] - min;
			}
		}
		return maxProfit;
	}
};
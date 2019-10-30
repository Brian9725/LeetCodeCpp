#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0, len = prices.size();
		for (int i = 1; i < len; i++) {
			if (prices[i] - prices[i - 1]>0)
				result += prices[i] - prices[i - 1];
		}
		return result;
	}
};
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size(), preMax = 0, curMax = 0;
		for (int i = 0; i < len; i++) {
			int temp = curMax;
			curMax = max(curMax, preMax + nums[i]);
			preMax = temp;
		}
		return curMax;
	}
};
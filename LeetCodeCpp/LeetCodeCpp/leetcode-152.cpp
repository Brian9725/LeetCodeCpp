#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int len = nums.size(), res = INT_MIN;
		vector<int> dpMax(len), dpMin(len);
		dpMax[0] = dpMin[0] = nums[0]; res = dpMax[0];
		for (int i = 1; i < len; ++i) {
			dpMax[i] = max(nums[i], max(nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]));
			if (dpMax[i] > res) res = dpMax[i];
			dpMin[i] = min(nums[i], min(nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]));
		}
		return res;
	}
};
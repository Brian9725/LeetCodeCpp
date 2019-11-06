#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len == 1)
			return nums[0];
		int max = nums[0], presum = nums[0];
		for (int i = 1; i < len; i++) {
			//当presum小于0时，可以开始一段新的子序列，不断更新和的最大值
			presum = (nums[i] > nums[i] + presum) ? nums[i] : (nums[i] + presum);
			if (presum > max)
				max = presum;
		}
		return max;
	}
};
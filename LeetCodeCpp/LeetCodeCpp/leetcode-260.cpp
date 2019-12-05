#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res, left, right;
		int len = nums.size(), tempRes = 0;
		for (int i = 0; i < len; ++i) {
			tempRes ^= nums[i];
		}
		//tempRes最低位的1一定是由那两个只出现一次的数计算成的，用此将这两个数分开
		tempRes = tempRes & (-tempRes);
		for (int i = 0; i < len; ++i) {
			if ((tempRes & nums[i]) == 0)
				left.push_back(nums[i]);
			else
				right.push_back(nums[i]);
		}
		int leftLen = left.size(), rightLen = right.size(), leftRes = 0, rightRes = 0;
		for (int i = 0; i < leftLen; ++i) {
			leftRes ^= left[i];
		}
		for (int i = 0; i < rightLen; ++i) {
			rightRes ^= right[i];
		}
		res.push_back(leftRes);
		res.push_back(rightRes);
		return res;
	}
};
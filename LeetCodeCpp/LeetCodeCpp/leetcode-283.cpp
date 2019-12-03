#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size(), idx = 0;
		for (int i = 0; i < len; ++i) {
			if (nums[i] != 0) nums[idx++] = nums[i];
		}
		for (int i = idx; i < len; ++i) {
			nums[i] = 0;
		}
	}
};
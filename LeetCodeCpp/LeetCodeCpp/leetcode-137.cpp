#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//ones表示出现一次的二进制位组成的数，twos鄙视出现两次的二进制位组成的数
		int ones = 0, twos = 0, len = nums.size();
		for (int i = 0; i < len; i++) {
			ones = (ones ^ nums[i]) & (~twos);
			twos = (twos ^ nums[i]) & (~ones);
		}
		return ones;
	}
};
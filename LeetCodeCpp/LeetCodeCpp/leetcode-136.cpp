#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//相同的数异或等于0，异或有交换律和结合律
	int singleNumber(vector<int>& nums) {
		int result = nums[0], len = nums.size();
		for (int i = 1; i < len; i++)
			result = result^nums[i];
		return result;
	}
};
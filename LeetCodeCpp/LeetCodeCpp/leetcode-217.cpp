#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int len = nums.size();
		if (len < 2)
			return false;
		map<int, int> numMap;
		for (int i = 0; i < len; i++) {
			if (numMap.find(nums[i]) != numMap.end())
				return true;
			else
				numMap[nums[i]] = 1;
		}
		return false;
	}
};
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> numMap;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (numMap.find(nums[i]) == numMap.end() || abs(i - numMap[nums[i]]) > k)
				numMap[nums[i]] = i;
			else
				return true;
		}
		return false;
	}
};
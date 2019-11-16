#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	//hash
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int len = nums.size();
		map<int, int> numMap;
		for (int i = 0; i < len; i++) {
			if (numMap.find(target - nums[i]) != numMap.end()) {
				result.push_back(numMap[target - nums[i]]);
				result.push_back(i);
				break;
			}
			numMap[nums[i]] = i;
		}
		return result;
	}

	/*
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int len = nums.size();
		for (int i = 0; i < len - 1; i++) {
			int temp = target - nums[i];
			for (int j = i + 1; j < len; j++) {
				if (temp == nums[j]) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
	*/
};
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int, int> numMap;
		int res = 0, len = nums.size();
		for (int i = 0; i < len; ++i) {
			numMap[nums[i]] = 1;
		}
		for (map<int, int>::iterator it = numMap.begin(); it != numMap.end(); ++it) {
			if (numMap.find(it->first - 1) != numMap.end()) continue;
			int tempRes = 1, curNum = it->first;
			while (numMap.find(curNum + 1) != numMap.end()) {
				tempRes++; curNum++;
			}
			res = max(res, tempRes);
		}
		return res;
	}
};
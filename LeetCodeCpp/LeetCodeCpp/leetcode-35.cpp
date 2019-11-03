#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1, mid = 0;
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (nums[mid] > target)
				high = mid - 1;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				return mid;
		}
		if (target > nums[mid])
			return mid + 1;
		return mid;
	}
};
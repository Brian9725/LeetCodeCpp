#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return -1;
		//minIdx为最小元素的下标
		int low = 0, high = len - 1, minIdx = 0;
		while (low <= high) {
			minIdx = (low + high) / 2;
			//nums[minIdx]<nums[high]时，minIdx在最小元素和nums[high]之间，可能等于最小元素
			if (nums[minIdx] < nums[high])
				high = minIdx;
			//nums[minIdx]>nums[high]时，minIdx在nums[low]和最小元素之间，不可能等于最小元素
			else if (nums[minIdx] > nums[high])
				low = minIdx + 1;
			//nums[minIdx]=nums[high]时，无法判断minIdx的具体位置
			//此时minIdx<=high，如果minIdx<high，将high-1可以保证最小元素仍在nums[low..high]中，如果minIdx=high，则有low=high，已经找到结果
			else
				high--;
		}
		return nums[minIdx];
	}
};
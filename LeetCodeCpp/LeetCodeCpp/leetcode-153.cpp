#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//与leetcode-33类似
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return -1;
		//minIdx为最小元素的下标
		int low = 0, high = len - 1, minIdx = 0;
		while (low <= high) {
			//nums[0]是大于nums[len-1]的，利用这个条件可以判断minIdx的大致位置
			minIdx = (low + high) / 2;
			if (minIdx > 0 && nums[minIdx] < nums[minIdx - 1])
				break;
			//如果nums[minIdx]比nums[len-1]都小，则其必在最小值和nums[len-1]之间
			else if (nums[minIdx] < nums[len - 1])
				high = minIdx - 1;
			//如果nums[minIdx]比nums[0]都大，则其必在nums[0]和最小值之间
			else
				low = minIdx + 1;
		}
		return nums[minIdx];
	}
};
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//在nums[low..high]上二分查找target
	int binSearch(vector<int>& nums, int low, int high, int target) {
		int result = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (target == nums[mid]) {
				result = mid; break;
			}
			else if (target >= nums[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return result;
	}

	//类似leetcode-154
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0)
			return false;
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
			else {
				//如果将nums[high]<nums[high-1]，将high-1虽然最终找到的下标minIdx也是最小元素的下标，但不是旋转点的下标
				if (high > 0 && nums[high] >= nums[high - 1])
					high--;
				else {
					minIdx = high; break;
				}
			}
		}
		int result = -1, mid = 0;
		if (minIdx == 0)
			result = binSearch(nums, 0, len - 1, target);
		//在nums[0..minIdx-1]上二分查找target
		else if (target >= nums[0])
			result = binSearch(nums, 0, minIdx - 1, target);
		//在nums[minIdx..len-1]上二分查找target
		else if (target <= nums[len - 1])
			result = binSearch(nums, minIdx, len - 1, target);
		else
			result = -1;
		if (result == -1)
			return false;
		return true;
	}
};
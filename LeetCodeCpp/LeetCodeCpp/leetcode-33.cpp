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
				result = mid;
				break;
			}
			else if (target >= nums[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return result;
	}

	//先二分查找数组中的最小值，以最小值为界便可以将数组分成两个升序的子数组，然后再二分查找
	int search(vector<int>& nums, int target) {
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
			//如果nums[minIdx]比nums[len-1]都小，则其比在最小值和nums[len-1]之间
			else if (nums[minIdx] < nums[len - 1])
				high = minIdx - 1;
			//如果nums[minIdx]比nums[0]都大，则其比在nums[0]和最小值之间
			else
				low = minIdx + 1;
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
		return result;
	}
};
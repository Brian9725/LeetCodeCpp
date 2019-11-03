#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.size() == 0) {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		//二分查找该元素是否存在
		int low = 0, high = nums.size() - 1, mid = 0;
		bool exist = false;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target) {
				exist = true; break;
			}
			else if (nums[mid] > target) 
				high = mid - 1;
			else 
				low = mid + 1;
		}
		if (!exist) {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		//在前半段查找元素第一次出现的位置
		low = 0; high = mid;
		int tempMid = 0;
		while (low < high) {
			tempMid = (low + high) / 2;
			if (nums[tempMid] == target) 
				high = tempMid;
			else 
				low = tempMid + 1;
		}
		result.push_back(low);
		//在后半段查找元素最后一次出现的位置
		low = mid; high = nums.size() - 1;
		while (low < high) {
			tempMid = (low + high) / 2 + 1;
			if (nums[tempMid] == target) 
				low = tempMid;
			else 
				high = tempMid - 1;
		}
		result.push_back(high);
		return result;
	}
};
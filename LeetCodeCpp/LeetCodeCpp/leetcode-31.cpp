#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//idx为最后一个使得nums[idx]<num[idx+]的下标，idx之后的数字全部按非递增排列
		int len = nums.size(), idx = 0, j = idx + 1, k = len - 1;
		for (int i = len - 1; i > 0; i--) {
			if (nums[i] > nums[i - 1]) {
				idx = i - 1;
				break;
			}
		}
		//将nums[idx]与其后最后一个比它大的数字交换位置
		bool isChanged = false;
		for (int i = idx + 1; i < len; i++) {
			if (nums[i] <= nums[idx]) {
				swap(nums[idx], nums[i - 1]);
				isChanged = true;
				//如果nums[idx]是与自身进行交换，则需要将nums[idx..len-1]逆序，否则将nums[idx+1..len-1]逆序
				if (i == idx + 1)
					j = idx;
				else
					j = idx + 1;
				break;
			}
		}
		//如果之前一直没有交换，将nums[idx]与nums[len-1]交换
		if (!isChanged) {
			swap(nums[idx], nums[len - 1]);
			j = idx + 1;
		}
		//将非递增排列的nums[j..k]逆序非递减排列
		while (j < k) {
			swap(nums[j], nums[k]);
			j++; k--;
		}
	}
};
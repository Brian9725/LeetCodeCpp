#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) {
			if (nums[0] == 1)
				return 2;
			else
				return 1;
		}
		//检查是否含有数字1
		bool hasOne = false;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 1) {
				hasOne = true; break;
			}
		}
		if (!hasOne)
			return 1;
		//将小于1和大于len的数用1代替
		for (int i = 0; i < len; i++) {
			if (nums[i] < 1 || nums[i] > len)
				nums[i] = 1;
		}
		//nums[i]为负表明i+1出现在nums中
		for (int i = 0; i < len; i++) {
			nums[abs(nums[i]) - 1] = 0 - abs(nums[abs(nums[i]) - 1]);
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] > 0)
				return i + 1;
		}
		return len + 1;
	}
};
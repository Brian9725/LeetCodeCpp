#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//排序数组
		sort(nums.begin(), nums.end());
		//dis表示三数和与target的差值
		int len = nums.size(), sum = 0, dis = 2147483647, result = 0;
		for (int i = 0; i < len - 2; i++) {
			for (int head = i + 1, tail = len - 1; head < tail;) {
				sum = nums[i] + nums[head] + nums[tail];
				if (dis > abs(sum - target)) {
					dis = abs(sum - target);
					result = sum;
				}
				if (sum > target) 
					tail--;
				else if (sum < target) 
					head++;
				else 
					return target;
			}
		}
		return result;
	}
};
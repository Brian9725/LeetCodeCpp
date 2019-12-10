#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	//滑动窗口法
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int res = INT_MAX, len = nums.size(), begin = 0, end = 0, sum = nums[begin];
		while (end < len) {
			//flag标记end是否到达末尾
			bool flag = false;
			while (sum < s) {
				if (end == len - 1) {
					flag = true; break;
				}
				sum += nums[++end];
			}
			if (flag) break;
			//此时nums[begin,end]已经是一个和大于s的子串，尝试将其缩短
			while (sum - nums[begin] > s) {
				sum -= nums[begin++];
			}
			//更新res值并将begin后移一位开始新一轮的窗口
			res = min(res, end - begin + 1);
			sum -= nums[begin++];
		}
		if (res == INT_MAX) res = 0;
		return res;
	}
};
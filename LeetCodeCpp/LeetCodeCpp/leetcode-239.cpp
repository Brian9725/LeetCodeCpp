#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> res, left(len), right(len);
		if (len == 0 || k == 0)
			return res;
		if (k == 1)
			return nums;
		//将nums按k个一组分块，最后一块可能没有k个元素，begin和end分别表示块的起点和终点
		//left[i]表示从每个块的开始到第i个元素的最大值，right[i]表示从块的结束到第i个元素的最大值
		int begin = 0, end = 0;
		while (begin < len) {
			//确定当前块的起点和终点
			if (begin + k < len)
				end = begin + k - 1;
			else
				end = len - 1;
			left[begin] = nums[begin]; right[end] = nums[end];
			for (int i = begin + 1; i <= end; i++) {
				left[i] = max(left[i - 1], nums[i]);
				right[end - (i - begin)] = max(right[end - (i - begin) + 1], nums[end - (i - begin)]);
			}
			begin = end + 1;
		}
		for (int i = 0; i <= len - k; i++) {
			res.push_back(max(left[i + k - 1], right[i]));
		}
		return res;
	}
};
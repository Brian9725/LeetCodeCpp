#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int len = nums.size();
		vector<string> res;
		int begin = 0, end = begin;
		while (begin < len) {
			while (end + 1 < len) {
				//避免两个相减的时候溢出
				long long num1 = nums[end + 1], num2 = nums[end];
				long long temp = num1 - num2;
				if (temp == 1)
					end++;
				else
					break;
			}
			string tempRes = to_string(nums[begin]);
			if (begin != end)
				tempRes += "->" + to_string(nums[end]);
			res.push_back(tempRes);
			begin = end + 1;
			end = begin;
		}
		return res;
	}
};
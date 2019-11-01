#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//dfs负责在nums[begin..nums.size()-1]中找出所有长度为num的子集
	void dfs(vector<vector<int>>& result, vector<int>& tempRes, vector<int>& nums, int begin, int num) {
		if (num == 0) {
			result.push_back(tempRes);
			return;
		}
		for (int i = begin; i < nums.size(); i++) {
			tempRes.push_back(nums[i]);
			//将nums[i]确立为子集的第一个元素后，只需在nums[i+1..nums.size()-1]中找出所有长度为num-1的子集
			dfs(result, tempRes, nums, i + 1, num - 1);
			tempRes.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		int len = nums.size();
		if (len == 0)
			return result;
		vector<int> tempRes;
		for (int i = 0; i < len + 1; i++) {
			//找出所有长度的i的子集
			dfs(result, tempRes, nums, 0, i);
		}
		return result;
	}
};